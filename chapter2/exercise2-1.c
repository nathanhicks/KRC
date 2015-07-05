/*
 * Exercise 2-1
 *
 * Write a program to determine the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation.  Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	char c_min,c_max,pc_max;
	unsigned char uc_min,uc_max,upc_max;
	short s_min,s_max,ps_max;
	unsigned short us_min,us_max,ups_max;
	int i_min,i_max,pi_max;
	unsigned int ui_min,ui_max,upi_max;
	long int li_min,li_max,pli_max;
	unsigned long uli_min,uli_max,upli_max;
	float f_min,f_max,pf_max;
	double d_min,d_max,pd_max;

	printf("Standard Header Values: \n");
	printf("signed char: min=%d,max=%d\n",SCHAR_MIN,SCHAR_MAX);
	printf("unsigned char: min=%d,max=%d\n",CHAR_MIN,CHAR_MAX);
	printf("signed short int: min=%d,max=%d\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned short int: min=%d,max=%d\n",0,USHRT_MAX);
	printf("signed int: min=%d,max=%d\n",INT_MIN,INT_MAX);
	printf("unsigned int: min=%u,max=%u\n",0,UINT_MAX);
	printf("signed long: min=%ld,max=%ld\n",LONG_MIN,LONG_MAX);
	printf("unsigned long: min=%lu,max=%lu\n",(long)0,ULONG_MAX);
	printf("float: min=%f,max=%f\n",FLT_MIN,FLT_MAX);
	printf("double: min=%f,max=%f\n",DBL_MIN,DBL_MAX);

	printf("Computational Values: \n");

	// Compute signed char min/max
	for (c_max = pc_max = 0; c_max >= pc_max; c_max++) {
		pc_max = c_max;
	}
	c_min = pc_max;
	c_min++;
	printf("signed char: min=%d,max=%d\n",c_min,pc_max);

	// Compute unsigned char min/max
	for (uc_max = upc_max = 0; uc_max >= upc_max; uc_max++) {
		upc_max = uc_max;
	}
	uc_min = upc_max;
	uc_min++;
	printf("unsigned char: min=%d,max=%d\n",uc_min,upc_max);

	// Compute signed short int min/max
	for (s_max = ps_max = 0; s_max >= ps_max; s_max++) {
		ps_max = s_max;
	}
	s_min = ps_max;
	s_min++;
	printf("short int: min=%d,max=%d\n",s_min,ps_max);
	
	// Compute unsigned short int min/max
	for (us_max = ups_max = 0; us_max >= ups_max; us_max++) {
		ups_max = us_max;
	}
	us_min = ups_max;
	us_min++;
	printf("unsigned short int: min=%d,max=%d\n",us_min,ups_max);

	// Compute signed int min/max
	for (i_max = pi_max = 0; i_max >= pi_max; i_max++) {
		pi_max = i_max;
	}
	i_min = pi_max;
	i_min++;
	printf("signed int: min=%d,max=%d\n",i_min,pi_max);

	// Compute unsigned int min/max
	for (ui_max = upi_max = 0; ui_max >= upi_max; ui_max++) {
		upi_max = ui_max;
	}
	ui_min = upi_max;
	ui_min++;
	printf("unsigned int: min=%u,max=%u\n",ui_min,upi_max);
	
	// Compute signed long int min/max
	for (li_max = pli_max = 0; li_max >= pli_max; li_max++) {
		pli_max = li_max;
	}
	li_min = pli_max;
	li_min++;
	printf("long int: min=%ld,max=%ld\n",li_min,pli_max);

	// Compute unsigned long int min/max
	for (uli_max = upli_max = 0; uli_max >= upli_max; uli_max++) {
		upli_max = uli_max;
	}
	uli_min = upli_max;
	uli_min++;
	printf("long int: min=%lu,max=%lu\n",uli_min,upli_max);

	// Couldn't find a way to calc floating point without taking advantage
	// of a known max value (which obviously isn't portable)
	// Below is still TODO
	// Compute float min/max
	for (f_max = pf_max = 0.0; f_max >= pf_max; pf_max+=0.1) {
		pf_max = f_max;
	}
	f_min = pf_max;
	f_min+=0.1;
	printf("float: min=%f,max=%f\n",f_min,pf_max);

}
