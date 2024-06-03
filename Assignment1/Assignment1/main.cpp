#define _CTR_SECURE_NO_WARNINGS
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
	text = (char**)malloc(rowsAmount * sizeof(char*));
	for (int i = 0; i < rowsAmount-1; i++)
	{
		text[i] = (char*)malloc(columnAmount * sizeof(char));
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
	for (idx; idx < strlen(text[curRow] - 1); idx++)
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
	printf("New line is started!\n");
}

void textPrint(void)
{
	for (int r = 0; r <= curRow; r++)
	{
		printf("%s", text[r]);
	}
	printf("\n");
}

//void saveToFile(void)
//{
//	printf("Enter the path to file: ");
//	char path[bufferSize];
//	fgets(path, bufferSize, stdin);
//	FILE* file = fopen(path, "w");
//	if (file != NULL)
//	{
//		for (int r = 0; r <= curRow; r++)
//		{
//			fputs((text[r],"\n"), file);
//		}
//	}
//	fclose(file);
//}
//
//void loadFromFile(void)
//{
//	printf("Enter the path to file: ");
//	char path[bufferSize];
//	fgets(path, bufferSize, stdin);
//	char lineFromFile[bufferSize];
//	int row = 0;
//	FILE* file = fopen(path, "r");
//	while (fgets(lineFromFile, bufferSize, file) != NULL) 
//	{
//		strcpy(text[row], lineFromFile);
//		row++;
//	}
//	curRow = row;
//	fclose(file);
//}

void search(void)
{
	printf("Enter the word you want to search: ");
	char word[bufferSize];
	fgets(word, bufferSize, stdin);
	int i = 0;
	for (int r = 0; r < curRow; r++)
	{
		for (int j = 0; j < strlen(text[r]) - 1; j++) 
		{
			if (text[r][j] == word[i])
			{
				if (i == strlen(word)-1)
				{
					printf("The word you search is in row %d starting on index %d", r, j-sizeof(word)+1);
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

//void insertText(void) 
//{
//	
//}

int main(void) 
{ 
	//to make a dynamic array!
	array2dMalloc();
	//printInfo();
	/*char input[16];
	printf("Enter a number: ");
	fgets(input, bufferSize, stdin);*/
	appendText();
	//newLine();
	appendText();
	textPrint();
	search();
	//free(input);
	return 0; 
}