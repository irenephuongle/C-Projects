//Irene Le

//This program is to convert hex to float
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
unsigned get_expf(float f);
int main(int argc, char *argv[])
{
	char input[1000] = {'\0'};
	int frac_bits = {23};
	int exp_bits = {8};	
	unsigned long l;
	unsigned short s;
	double d;
	unsigned int frac_mask1 = 0x1 << frac_bits;
	unsigned int s_mask1;
	unsigned int exp_mask1 = 0xFF << 23;
	unsigned int pmask = 0x1 << (frac_bits + exp_bits);
	unsigned long exp =0;
	int exp1 = 0;
	double frac = {0};
	int sign = 0;	
	float f;
	if(argc == 2)
	{

			if(strcmp(argv[1], "-H") == 0)
			{
				printf("Usage: ./hex-2-float [OPTION ...]\n\t-i file_name specify the name of the input file (defaults to stdin\n\t-d use settings for double precision (double, 64-bits, 1-11-52)\n\t-h use settings for half precision (binary16, 16bits, 1-5-10)\n\t-b use settings for half preciison (bfloat16, 16-bits, 1-8-10)\n\t-m use settings for quarter precision (minifloat, 8-bits, 1-4-3 bias -2)\n\t-e # set the number of bits to use for the exponent\n\t-E # set the value used for the exponent bias\n\t-f # set the number of bits to use for the fraction\n\t-F set the value to add to the fraction\n\t-v display the settings (to stderr) before reading input\n\t-H display this help message and exit\n");



			}	

		if(strcmp(argv[1], "-b") == 0)
		{







		}

		if(strcmp(argv[1], "-h") == 0)
		{
			frac_bits = 10;
			exp_bits = 5;
			//GET THE HEX VALUE
			printf("Enter the hex value: \n");
			fgets(input,1000,stdin);
			sscanf(input, "%hx", &s);
			printf("0x%hx\n", s);
			//SIGN MASK
			s_mask1 = s >> 15;	
			//STORE SIGN VALUE
			sign = (s & s_mask1) ? 1 : 0;

			exp_mask1 = 0x1;	
			//EXPONENT MASK	
			for(int i = 0; i < exp_bits - 1; i++)
			{
				exp_mask1 <<= 1; //BUILD MASK
				exp_mask1 |= 0x1; //ONE BIT AT A TIME
			}
			exp_mask1 <<= frac_bits; //SHIFT INTO PLACE
					
			if(exp == 0)
			{
			}
			if(exp == exp_mask1)
			{
				if(frac == 0)
				{
				}
				else
				{
				}	
			}		
					
			//FRACTION MASK
			frac_mask1 = 0x1;
		
			for(int i = 0; i < frac_bits - 1; i++)
			{
				frac_mask1 <<= 1; //BUILD MASK
				frac_mask1 |= 0x1; //ONE BIT AT A TIME
			}
		frac = frexp(s, &exp1);

		pmask = 0x1 << (frac_bits + exp_bits);
		//print sign
		printf("\t%d ", sign);
		for(int i = exp_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print exponent bits
			printf("%d", (s & pmask) ? 1 : 0);
		}
		printf(" ");
		for(int i = frac_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print fraction bits
			printf("%d", (s & pmask) ? 1 : 0);
		}
		printf("\n");

		//Print s ,e , f		
		printf("\ts ");
		for(int i = 1; i <= 5; i++)
		{
			printf("e");
		}
		printf(" ");
		for(int i = 1; i<= 10; i++)
		{
			printf("f");
		}
		printf("\n");	

		//print if sign is positive or negative
		printf("\tsign:");
		if(sign > 0)
		{
			printf("\t\tnegative\n");
		}
		else
		{
			printf("\t\tpositive\n");
		}
	
		//print the exponent
		printf("\texponent:");
		printf("\t%d\n", exp1);

		//print the fraction
		printf("\tfraction:");
		printf("\t%f\n", frac);

		//print the float value
		printf("\tvalue:");
		printf("\t\t%.20d\n", s);

		printf("\tvalue:");
		printf("\t\t%.20d\n",s);
		
		}

		if(strcmp(argv[1], "-d") == 0)
		{
			frac_bits = 52;
			exp_bits = 11;
			//GET THE HEX VALUE
			printf("Enter the hex value: \n");
			fgets(input,1000,stdin);
			sscanf(input, "%lx", &l);
			printf("0x%lx\n", l);
			d = *((double*)&l);	
			//SIGN MASK
			s_mask1 = l >> 63;	
			//STORE SIGN VALUE
			sign = (l & s_mask1) ? 1 : 0;

			exp_mask1 = 0x1;	
			//EXPONENT MASK	
			for(int i = 0; i < exp_bits - 1; i++)
			{
				exp_mask1 <<= 1; //BUILD MASK
				exp_mask1 |= 0x1; //ONE BIT AT A TIME
			}
			exp_mask1 <<= frac_bits; //SHIFT INTO PLACE
					
			if(exp == 0)
			{
			}
			if(exp == exp_mask1)
			{
				if(frac == 0)
				{
				}
				else
				{
				}	
			}		
					
			//FRACTION MASK
			frac_mask1 = 0x1;
		
			for(int i = 0; i < frac_bits - 1; i++)
			{
				frac_mask1 <<= 1; //BUILD MASK
				frac_mask1 |= 0x1; //ONE BIT AT A TIME
			}
		frac = frexp(l, &exp1);

		pmask = 0x1 << (frac_bits + exp_bits);
		//print sign
		printf("\t%d ", sign);
		for(int i = exp_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print exponent bits
			printf("%d", (l & pmask) ? 1 : 0);
		}
		printf(" ");
		for(int i = frac_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print fraction bits
			printf("%d", (l & pmask) ? 1 : 0);
		}
		printf("\n");

		//Print s ,e , f		
		printf("\ts ");
		for(int i = 1; i <= 11; i++)
		{
			printf("e");
		}
		printf(" ");
		for(int i = 1; i<= 52; i++)
		{
			printf("f");
		}
		printf("\n");	

		//print if sign is positive or negative
		printf("\tsign:");
		if(sign > 0)
		{
			printf("\t\tnegative\n");
		}
		else
		{
			printf("\t\tpositive\n");
		}
	
		//print the exponent
		printf("\texponent:");
		printf("\t%d\n", exp1);

		//print the fraction
		printf("\tfraction:");
		printf("\t%f\n", frac);

		//print the float value
		printf("\tvalue:");
		printf("\t\t%.20f\n", d);

		printf("\tvalue:");
		printf("\t\t%.20e\n",d);
		
		}
}
//return 0;
	if(argc == 1)
	{
	frac_bits = 23;
	exp_bits = 8;
	frac_mask1 = 0x1 << frac_bits;
	 exp_mask1 = 0xFF << 23;
	pmask = 0x1 << (frac_bits + exp_bits);
	
		//GET THE HEX VALUE
		printf("Enter the hex value: \n");
		fgets(input,1000,stdin);
		sscanf(input, "%lx", &l);
		printf("0x%lx\n", l);
		f = *((float*)&l);	
		//SIGN MASK
		s_mask1 = l >> 31;	
		//STORE SIGN VALUE
		sign = (l & s_mask1) ? 1 : 0;

		exp_mask1 = 0x1;	
		//EXPONENT MASK	
		for(int i = 0; i < exp_bits - 1; i++)
		{
			exp_mask1 <<= 1; //BUILD MASK
			exp_mask1 |= 0x1; //ONE BIT AT A TIME
		}
		exp_mask1 <<= frac_bits; //SHIFT INTO PLACE
		exp = get_expf(f) -127;		
		if(exp == 0)
		{
		}
		if(exp == exp_mask1)
		{
			if(frac == 0)
			{
			}
			else
			{
			}	
		}		
				
		//FRACTION MASK
		frac_mask1 = 0x1;
	
		for(int i = 0; i < frac_bits - 1; i++)
		{
			frac_mask1 <<= 1; //BUILD MASK
			frac_mask1 |= 0x1; //ONE BIT AT A TIME
		}
		frac = (l & frac_mask1);
//PRINT EVERYTHING
	
		//print sign
		printf("\t%d ", sign);
//		printf("\t%d ", (l & pmask) ? 1 : 0);
		for(int i = exp_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print exponent bits
			printf("%d", (l & pmask) ? 1 : 0);
		}
		printf(" ");
		for(int i = frac_bits; i > 0; i--)
		{
			pmask >>= 1;
			//print fraction bits
			printf("%d", (l & pmask) ? 1 : 0);
		}
		printf("\n");


		//Print s ,e , f		
		printf("\ts ");
		for(int i = 1; i <= 8; i++)
		{
			printf("e");
		}
		printf(" ");
		for(int i = 1; i<= 23; i++)
		{
			printf("f");
		}
		printf("\n");	

		//print if sign is positive or negative
		printf("\tsign:");
		if(sign > 0)
		{
			printf("\t\tnegative\n");
		}
		else
		{
			printf("\t\tpositive\n");
		}
	
		//print the exponent
		printf("\texponent:");
		printf("\t%lu\n", exp);

		//print the fraction
		printf("\tfraction:");
		printf("\t%f\n", frac);

		//print the float value
		printf("\tvalue:");
		printf("\t\t%.20f\n", f);

		printf("\tvalue:");
		printf("\t\t%.20e\n",f);
		
	}	
		
return 0;
}
unsigned get_expf(float f)
{
	union {
	unsigned o;
	float f;
	} of;
	
	of.f = f;
	return (of.o >> 23) & 0xff;



}


