#include <stdio.h> 
#include <stdlib.h>

size_t bufferSize = 256;
char** text;
int rowsAmount = 10;

void array2dMalloc(char** arr) 
{
	arr = (char**)malloc(rowsAmount * sizeof(char*));
	for (int i = 0; i < rowsAmount; i++)
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


int main(void) 
{ 
	array2dMalloc(text);
	printInfo();
	char* input = (char*)malloc(bufferSize * sizeof(char));
	printf("Enter a number: ");
	fgets(input, bufferSize, stdin);
	//free(input);
	return 0; 
}