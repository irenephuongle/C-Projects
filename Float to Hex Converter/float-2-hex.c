//Irene Le

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//make a float variable for the float input
	char input[1000]= {0};
	char *end_ptr;
	float f_value = {0};	
	double d_value = {0};
	unsigned int hex = {0};
	long unsigned int long_hex = {0};
	if(argc >= 1)
	{

		//If they use -f, -d, or -H
		if(argc > 1)
		{	//if they use -d
			if(strcmp(argv[1], "-d") == 0)
			{
				printf("Enter a double value:\n");
				fgets(input, 1000, stdin);
				d_value = strtod(input, &end_ptr);
				long_hex = (unsigned long)d_value;			
				memcpy(&long_hex, &d_value, sizeof(long_hex));
				printf("%-40s\t%.16le\t%.16lf\t0x%016lx\n", input, d_value, d_value, long_hex);
				return 0;
			}
			//if they use -H
			if(strcmp(argv[1], "-H") == 0)
			{
				printf("Usage: ./float-2-hex [OPTION ...]\n\t-f convert the input into floats for hex output (this is the default)\n\t-d convert the input into doubles for the hex output\n\t-H display this help message and exit\n");
			return 0;
			}	
			if(strcmp(argv[1], "-f") == 0)
			{
			
			printf("Enter a float value:\n");
			//get input
			fgets(input,1000, stdin);
			//convert input (string) to float
			f_value = strtof(input, &end_ptr);	
			memcpy(&hex, &f_value, sizeof(hex));
			printf("%-40s\t%.10e\t%.10f\t0x%08x\n", input, f_value, f_value, hex);
			return 0;
			}
		}
		else
		{
		
		printf("Enter a float value:\n");
		//get input
		fgets(input,1000, stdin);
		//convert input (string) to float
		f_value = strtof(input, &end_ptr);	
		memcpy(&hex, &f_value, sizeof(hex));
		printf("%-40s\t%.10e\t%.10f\t0x%08x\n", input, f_value, f_value, hex);
		return 0;
		}

	}


return EXIT_SUCCESS;
}
