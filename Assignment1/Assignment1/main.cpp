#include <stdio.h> 

void print_info(void) 
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
	print_info();
	return 0; 
}