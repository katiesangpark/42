#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>


unsigned int ft_strlen(char *str);
int ft_tolower(int c);
void	ft_memcpy(void *dest, void *src, unsigned int size);
char *ft_strchr(char *str, char c);
void	ft_bzero(void *ptr, unsigned int nbr);
void	ft_memset(void *ptr, int value, unsigned int nbr);
int	ft_strcmp(char *s, char *s2);

int main(int ac, char **av)
{
	char *s = "This is a test string.42.";
	char *s2 = malloc(128);
	ft_memcpy(s2, s, ft_strlen(s) + 1);
	printf("%s\n", s2);
//	for(int i = 0; i < 200000000; i++)
//		ft_strcmp("THIS IS a !test STRING", "THIS IS a !test STRING");
	/*char *str = strdup("THIS IS a !test STRING");
	ft_memset(str + 5, 'a', 2);
	printf("[%d]\n", str[0]);
	printf("[%d]\n", str[1]);
	printf("%s\n", str);
	char *str2 = ft_strchr(str, '!');
	printf("%s\n", str2);
	char *str3 = ft_strchr(str, 'x');
	printf("%s\n", str3);*/
	/*char *str = strdup("THIS IS a test STRING");

	for (int i = 0; str[i]; i++)
		str[i] = ft_tolower(str[i]);
	printf("%s\n",  str);*/


	/*char *str;

	if (ac == 1)
		str = "This is a test string";
	else
		str = av[1];
	printf("Len is (%u), true len is (%lu)\n", ft_strlen(0), strlen(str));

	printf("--Benchmark--\n");
	for(unsigned long long i = 0; i < 100000000; i++)
		ft_strlen(0);*/
	return (0);
}