#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	counter = 0;
		while(argv[1][counter])
			counter++;
		while((argv[1][counter - 1] == 32 || argv[1][counter - 1] == '\t') && counter > 0)
			counter--;		
		while((argv[1][counter - 1] != 32 && argv[1][counter - 1] != '\t') && counter > 0)
			counter--;
		while((argv[1][counter] != 32 && argv[1][counter] != '\t') && argv[1][counter])
		{
			write(1, &argv[1][counter], 1);
			counter++;
		}
	}
	write (1, "\n", 1);
}