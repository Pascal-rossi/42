// #include <stdlib.h>
// #include <stdio.h>



// // int	main()
// // {
// // 	char	**result = ft_split("  Hello\tworld\nthis is 42 ");
// // 	int		i = 0;

// // 	while (result && result[i])
// // 	{
// // 		printf("[%s]\n", result[i]);
// // 		free(result[i]);
// // 		i++;
// // 	}
// // 	free(result);
// // 	return (0);
// // }
// #include<unistd.h>
// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}	
// }

// int	main(int argc, char **argv)
// {
// 	char	**words;
// 	int		count;

// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return (0);
// 	}
// 	words = ft_split(argv[1]);
// 	if (!words)
// 		return (1);
// 	count = 0;
// 	while (words[count])
// 		count++;
// 	while (--count >= 0)
// 	{
// 		ft_putstr_fd(words[count],1);
// 		if (count > 0)
// 			write(1, " ", 1);
// 		free(words[count]);
// 	}
// 	free(words);
// 	write(1, "\n", 1);
// 	return (0);
// }
int is_seperator(char c)
{
	return (c == ' ' || c == '\t' || c== '\n');
}
int count_word(char *str)
{
	int i = 0;
	int count = 0; 
	int in_word = 0;
	while(str[i])
	{
		if(!is_seperator(str[i]) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if(is_seperator(str[i]))
			in_word = 0;
		i++;
	}
	return(count);
}
char *dup_word(char *str, int len)
{
	int i =0;
	char *s;
	s = (char *)malloc(sizeof(char ) * (len + 1));
	if(!s)
		return (NULL);
	while(str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
void freeall(char **tab, int last)
{
	while(last>=0)
	{
		free(tab[last]);
		last--;
	}
	free (tab);
}
char **split(char *str)
{
	char **tab;
	int word =0;
	int i = 0;
	
	tab = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	if(!tab)
		return (NULL);
	while(*str)
	{
		if(!is_seperator(*str))
		{
			int len = 0;
			while(!is_seperator(str) && str[len])
				len++;
			tab[i] = dup_word(str, len);
			if(!tab[i])
			{
				freeall(tab, len -1);
				return(NULL);
			}
			str+=len;
			i++;
		}else
			str++;
	}
	tab[i] = NULL;
}