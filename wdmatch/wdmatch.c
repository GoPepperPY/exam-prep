#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	lenght = 0, counter1 = -1, counter2 = -1, check = 0;
		while(argv[1][lenght])
			lenght++;
		while(argv[1][++counter1])
		{
			while(argv[2][++counter2])
			{
				if(argv[2][counter2] == argv[1][counter1])
				{
					check++;
					break ;
				}
			}
		}
		if (check == lenght)
		{
			write(1, argv[1], check);
		}
	}
	write(1, "\n", 1);
}