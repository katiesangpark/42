#include <stdio.h>
#include <string.h>
#include <limits.h>

unsigned int slen(char *str);
int ft_tolower(int c);

int main(int ac, char **av)
{
	/*char *str = strdup("THIS IS a test STRING");

	for (int i = 0; str[i]; i++)
		str[i] = ft_tolower(str[i]);
	printf("%s\n",  str);*/
	char *str;

	if (ac == 1)
		str = "This is a test string";
	else
		str = av[1];
	printf("Len is (%u), true len is (%lu)\n", slen(str), strlen(str));

	printf("--Benchmark--\n");
	for(unsigned long long i = 0; i < 100000000; i++)
		slen(str);
	return (0);
}