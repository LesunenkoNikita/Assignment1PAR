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


int main(void) 
{ 
	//to make a dynamic array!
	array2dMalloc();
	/*loadFromFile();
	textPrint();*/
	//printInfo();
	/*char input[16];
	printf("Enter a number: ");
	fgets(input, bufferSize, stdin);*/
	appendText();
	newLine();
	appendText();
	textPrint();
	//savetofile();
	search();
	//free(input);
	return 0; 
}