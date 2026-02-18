#include <unistd.h>

int	check_doubles(char c, char *str, int lenght)
{
	int	counter = -1;
	while(str[++counter] && counter < lenght)
	{
		if (str[counter] == c)
			return (1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	counter = 0;

	while(str[counter])
		counter++;
	return counter;
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		int	counter = -1;
		while (argv[1][++counter])
		{
			if(!check_doubles(argv[1][counter], argv[1], counter) && \
			check_doubles(argv[1][counter], argv[2], ft_strlen(argv[2])) == 1)
				write(1, &argv[1][counter], 1);
		}
	}
	write(1, "\n", 1);
}