/*
 * Exercise 2-3
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 *
 */
#include <stdio.h>
#include <limits.h>

int htoi(char s[]);

int main()
{
	int test = htoi("0xAA");
	printf("= %d\n",test);

	return 0;
}

int htoi(char s[])
{
	int i = 0;
	unsigned long value = 0;
	if(s[i] != '0') {
		return 0;
	}
	++i;
	if(s[i] != 'x' && s[i] != 'X') {
		return 0;
	}
	++i;
	while(value < ULONG_MAX / 16) {
		if(s[i] >= '0' && s[i] <= '9') {
			value *= 16;
			value += s[i] - '0';
		} else if(s[i] >= 'a' && s[i] <= 'f') {
			value *= 16;
			value += s[i] - 'a' + 10;
		} else if(s[i] >= 'A' && s[i] <= 'F') {
			value *= 16;
			value += s[i] - 'A' + 10;
		} else {
			return value;
		}
		++i;
	}
	return value;
}
