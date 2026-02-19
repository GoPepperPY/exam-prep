#include <stdlib.h>
#include <stdio.h>

void fprime(int nb)
{
	int	prime;

	prime = 2;
	while(nb > 1)
	{
		if (nb % prime == 0)
		{
			nb = nb / prime;
			printf("%d", prime);
			if(nb > 1)
				printf("*");
			prime--;
		}
		prime++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
}