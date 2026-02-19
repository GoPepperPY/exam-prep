#include <stdlib.h>
#include <stdio.h>

int	signal(int x)
{
	if (x < 0)
		return(-x);
	return(x);
}

int     *ft_range(int start, int end)
{
	int	*array, counter, size = signal(end - start) + 1;

	array = (int *)malloc(sizeof(int) * size);
	if(array == NULL)
		return(0);
	
	if(end < start)
	{
		counter = 0;
		while(counter < size)
		{
			array[counter] = start - counter;
			counter++;
		}
	}
	else if(end > start)
	{
		counter = 0;
		while(counter < size)
		{
			array[counter] = start + counter;
			counter++;
		}
	}
	else
		array[0] = start;
	counter = -1;
	while(array[++counter])
		printf("%d\n", array[counter]);
	return(array);
}

int main(void)
{
	int *array = ft_range(1, 1);
}