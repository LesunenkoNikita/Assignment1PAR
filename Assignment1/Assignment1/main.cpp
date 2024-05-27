#include <stdio.h> 
#include <stdlib.h>

size_t bufferSize = 256;
char** text;
int rowsAmount = 10;
int curRow = 0;

void array2dMalloc(char** arr) 
{
	arr = (char**)malloc(rowsAmount * sizeof(char*));
	for (int i = 0; i < rowsAmount-1; i++)
	{
		arr[i] = (char*)calloc(bufferSize, sizeof(char));
	}
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
7 - To search text");
} 

void appendText(void)
{
	printf("Enter the text you want to append: ");
	char* input = (char*)malloc(bufferSize * sizeof(char));
	fgets(input, bufferSize, stdin);
	int idx = 0;
	for (idx; idx < sizeof(text[curRow] - 1); idx++)
	{
		if (text[curRow][idx] = '\0')
		{
			break;
		}
	}
	for (int i = 0; i < sizeof(input)-1; i++)
	{
		text[curRow][idx] =input[i];
		idx++;
	}
	free(input);
}

void newLine(void)	
{
	curRow++;
	printf("New line is started");
}

void textPrint(void)
{
	for (int r = 0; r <= curRow; r++)
	{
		/*for (int i = 0; i < sizeof(text[r]) - 1; i++)
		{
			if (text[r][i] = '\0')
			{
				printf("\n");
				break;
			}
			else
			{
				printf("%c", text[r][i]);
			}
		}*/
		printf("%s\n", text[r]);
	}
}



int main(void) 
{ 
	//to make a dynamic array!
	array2dMalloc(text);
	printInfo();
	char* input = (char*)malloc(bufferSize * sizeof(char));
	printf("Enter a number: ");
	fgets(input, bufferSize, stdin);
	//free(input);
	return 0; 
}