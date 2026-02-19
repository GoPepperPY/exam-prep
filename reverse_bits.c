#include <stdio.h>

unsigned char reverse(unsigned char octet)
{
	unsigned char c = 0;
	int	counter = 8;
	while(counter--)
	{
		c = ((1 << c) | (octet & 1));
		octet = octet >> 1;
	}
	return (c);
}

int main(void)
{
	unsigned char c = reverse((unsigned char)5), bit = 0;
	int	counter = 8;
	while (counter--)
	{
		bit = (c >> counter & 1) + 48;
		printf("%c", (unsigned char)bit);
	}
	
	printf("%c", c);
}
