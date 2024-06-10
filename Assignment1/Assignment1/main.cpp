#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

const size_t bufferSize = 256;
char** text;
int columnAmount = 256;
int rowsAmount = 10;
int curRow = 0;

void array2dMalloc(void) 
{
	text = (char**)calloc(rowsAmount, sizeof(char*));
	for (int i = 0; i < rowsAmount; i++)
	{
		text[i] = (char*)calloc(columnAmount, sizeof(char));
	}
	text[0][0] = '\0';
}

void printInfo(void) 
{ 
	printf("All available commands:\n\
1 - To append text symbols to the end\n\
2 - To start a new line\n\
3 - To save the text into a file\n\
4 - To load the text from the file\n\
5 - To print current text to console\n\
6 - To insert the text by line and symbol index\n\
7 - To search text\n");
} 

void appendText(void)
{
	printf("Enter the text you want to append: ");
	char* input = (char*)malloc(bufferSize * sizeof(char));
	fgets(input, bufferSize, stdin);
	if (sizeof(input) > (columnAmount - sizeof(text[curRow]))) 
	{
		columnAmount *= 2;
		for (int i = 0; i < rowsAmount; i++)
		{
			text[i] = (char*)realloc(text[i], columnAmount * sizeof(char));
		}
	}
	int idx = 0;
	for (idx; idx < strlen(text[curRow]); idx++)
	{
		if (text[curRow][idx] == '\0')
		{
			break;
		}
	}
	for (int i = 0; i < strlen(input)-1; i++)
	{
		text[curRow][idx] =input[i];
		idx++;
	}
	text[curRow][idx] = '\0';
	free(input);
}

void newLine(void)	
{
	if (curRow + 1 == rowsAmount)
	{
		rowsAmount *= 2;
		text = (char**)realloc(text, rowsAmount * sizeof(char*));
		for (int i = curRow + 1; i < rowsAmount; i++)
		{
			text[i] = (char*)realloc(text[i], columnAmount * sizeof(char));
		}
	}
	curRow++;
	text[curRow][0] = '\0';
	printf("New line is started!\n");
}

void textPrint(void)
{
	for (int r = 0; r <= curRow; r++)
	{
		printf(text[r]);
		printf("\n");
	}
}

void saveToFile(void)
{
	printf("Enter the path to the file: ");
	char path[bufferSize];
	fgets(path, bufferSize, stdin);
	path[strcspn(path,"\n")] = '\0';
	FILE* file = fopen(path, "w");
	if (file != NULL)
	{
		for (int r = 0; r <= curRow; r++)
		{
			fputs(text[r], file);
			fputs("\n", file);
		}
	}
	fclose(file);
}

void loadFromFile(void)
{ 
	printf("Enter the path to file: ");
	char path[bufferSize];
	fgets(path, bufferSize, stdin);
	path[strcspn(path, "\n")] = '\0';
	char lineFromFile[bufferSize];
	int row = 0;
	FILE* file = fopen(path, "r");
	while (fgets(lineFromFile, bufferSize, file) != NULL) 
	{
		strcpy(text[row], lineFromFile);
		row++;
	}
	curRow = row;
	text[curRow-1][strlen(text[curRow-1])] = '\0';
	fclose(file);
}

void search(void)
{
	printf("Enter the word you want to search: ");
	char word[bufferSize];
	fgets(word, bufferSize, stdin);
	word[strcspn(word, "\n")] = '\0';
	int i = 0;
	for (int r = 0; r <= curRow; r++)
	{
		for (int j = 0; j < strlen(text[r]); j++)
		{
			if (text[r][j] == word[i])
			{
				if (i == strlen(word)-1)
				{
					printf("The word you search is in row %d starting on index %d\n", r, j-strlen(word)+1);
					i = 0;
				}
				else
				{
					i++;
				}
			}
			else
			{
				i = 0;
			}
		}
	}
}

void insertText(void)
{
	printf("Choose line and index: ");
	char input[bufferSize];
	fgets(input, bufferSize, stdin);
	input[strcspn(input, "\n")] = '\0';
	int row, idx;
	sscanf(input, "%d %d", &row, &idx);
	row--;
	printf("Enter text to insert: ");
	char word[bufferSize];
	fgets(word, bufferSize, stdin);
	word[strcspn(word, "\n")] = '\0';
	if (sizeof(word) > (columnAmount - sizeof(text[row])))
	{
		columnAmount *= 2;
		for (int i = 0; i < rowsAmount; i++)
		{
			text[i] = (char*)realloc(text[i], columnAmount * sizeof(char));
		}
	}
	int len = strlen(word);
	for (int i = strlen(text[row]); i >= idx; i--)
	{
		text[row][i + len] = text[row][i];
	}
	for (int n = 0; n < len; n++)
	{
		text[row][idx] = word[n];
		idx++;
	}
}


int main(void) 
{ 
	array2dMalloc();
	printInfo();
	while (1)
	{
		printf("Enter the command: ");
		char* input = (char*)malloc(bufferSize * sizeof(char));
		fgets(input, bufferSize, stdin);
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "1") == 0)
		{
			appendText();
			free(input);
			continue;
		}
		else if (strcmp(input, "2") == 0)
		{
			newLine();
			free(input);
			continue;
		}
		else if (strcmp(input, "3") == 0)
		{
			saveToFile();
			free(input);
			continue;
		}
		else if (strcmp(input, "4") == 0)
		{
			loadFromFile();
			free(input);
			continue;
		}
		else if (strcmp(input, "5") == 0)
		{
			textPrint();
			free(input);
			continue;
		}
		else if (strcmp(input, "6") == 0)
		{
			insertText();
			free(input);
			continue;
		}
		else if (strcmp(input, "7") == 0)
		{
			search();
			free(input);
			continue;
		}
	}
	return 0; 
}