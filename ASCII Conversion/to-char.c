//Irene Le

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int decimal = 0;
	int octal = 0;
	int hex = 0;

	char base[10] = {'\0'};
	printf("Enter in the value base: ");
	fgets(base, 10, stdin);

	//if they choose 10 (decimal input)
	if(strcmp(base, "10\n") == 0)
	{	
		printf("decimal input\n");
		for(int i = 0; scanf("%d", &decimal) && decimal != 0; i++)
		{
			printf("%c", decimal);
		}	
		printf("\n");
	return 0;
	}
	
	//if they choose 8 (octal input)
	if(strcmp(base, "8\n") == 0)
	{
		printf("octal input\n");
		for(int i = 0; scanf("%i", &octal) && octal != 0; i++)
		{
			printf("%c", octal);
		}
		printf("\n");
	return 0;
	}	

	//if they choose 16 (hex input)
	if(strcmp(base, "16\n") == 0)
	{
		printf("hex input\n");
		for(int i = 0; scanf("%i", &hex) && hex != 0; i++)
		{
			printf("%c", hex);
		}
		printf("\n");
	return 0;
	}


	else
		printf("Error, base must be 8, 10, or 16\n");


return 0;
}



