/*

	half way through the program, i realized i did not have to do the mathematical 
	arithmetic in order to find the ascii values of the string, so i changed the way
	i was doing the program halfway though


*/


//Irene Le
//10.18.2022
//This program will read a line of text from the keyboard and display the number 
//ASCII values of each character (OCTAL, DECIMAL & HEX)

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100 //MAX NUM OF CHARACTERS READ IN FROM USER
void convert_decimal(char text[], int decimal[]);
void convert_octal(int decimal[], int octal[]);
void convert_hex(int decimal[], char hex[]);

void print_decimal(int decimal[]);
void print_octal(int octal[]);
int main(void)
{
	//The text from the user has to be 100 characters or less
	char text[MAX] = {'\0'}; // \0 is at text[100]
	
	//These are the arrays we are storing the ASCII values in
	int decimal[100] = {0};
	int octal[100] = {0};
	char hex[100] = {0};

	//Tell the user to enter a line
	printf("Please enter a single line of text: \n");
	//Read in the text from the user
	fgets(text, MAX, stdin);
	//Convert the text to decimal
	convert_decimal(text, decimal);
	
	//Convert decimal to octal
	printf("octal output\n");
	convert_octal(decimal, octal);

	printf("\ndecimal output\n");
	print_decimal(decimal);
	//Convert decimal to hex
	printf("\nhex output\n");
	convert_hex(decimal, hex);
	printf("\n");

return 0;

}

//Function to copy contents of text array into ASCII arrays

//Function to copy text to DECIMAL
void convert_decimal(char text[], int decimal[])
{	int i =0;
	for(; text[i] != 0; ++i)
	{
		decimal[i] = (text[i] + 0);
	}
	decimal[i] = '\n';
return;
}
void print_decimal(int decimal[])
{
	for(int i = 0; decimal[i] != '\n'; ++i)
	{
		printf("%d ", decimal[i]);
	}
return; 
}
//Function to copy text to OCTAL
void convert_octal(int decimal[], int octal[])
{
	//converting decimal to octal
	int j = 0;
	int number = decimal[j];
	do{
		int remainder = 0;
		int i = 1;
		while(number)
		{
			remainder = number % 8;
			octal[j] += remainder * i;
			number = number / 8;
			i = i*10;
		}
	if(octal[j] <= 99 && octal[j] != '\n')
	{
		printf("00%d ", octal[j]);
	}
	if(octal[j] != '\n')
	{
	printf("0%d ", octal[j]);
	}
	j++;
	number = decimal[j];
	}while(decimal[j] != '\n');
return;
}
//Convert decimal to hex
void convert_hex(int decimal[], char hex[])
{
	for(int i = 0; decimal[i] != '\n'; i++)
	{
		printf("0x%X ", decimal[i]);
	}
return;
}
