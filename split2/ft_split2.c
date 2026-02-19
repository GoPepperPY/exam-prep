#include <stdio.h>
#include <stdlib.h>

int check_sep(char c)
{
	if (c == 32 || c == '\t' || c == '\n')
		return (1);
	return(0);
}

int	count_words(char *str)
{
	int	counter = -1, words = 0;
	if(!check_sep(str[0]))
		words++;
	while(str[++counter])
	{
		if (!check_sep(str[counter]) && check_sep(str[counter - 1]))
			words++;
	}
	return (words);
}

char	*ft_strdup(char *str)
{
	int	counter = 0;
	char *dup;
	while(!check_sep(str[counter]) && str[counter])
		counter++;
	dup = (char *)malloc(sizeof(char) * counter + 1);
	counter = 0;
	while(!check_sep(str[counter]) && str[counter])
	{
		dup[counter] = str[counter];
		counter++;
	}
	dup[counter] = '\0';
	return(dup);
}

char	**ft_split(char *str)
{
	char **split = (char **)malloc(sizeof(char *) + count_words(str) + 1);
	int counter = -1;
	while(str[0])
	{
		while(check_sep(str[0]) && str[0])
			str++;
		if(str[0])
			split[++counter] = ft_strdup(str);
		while(!check_sep(str[0]) && str[0])
			str++;
	}
	split[++counter] = 0;
	return (split);
}

int main(void)
{
	char	**split = ft_split("   ola como estas");
	int	counter = -1;

	while(split[++counter])
		printf("%s\n", split[counter]);
}

// "como estas"
// [0] ola
// [1] como
// [2] estas
