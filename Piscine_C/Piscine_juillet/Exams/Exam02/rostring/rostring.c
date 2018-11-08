/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:56:54 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 19:16:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			i -= 1;
			count++;
		}
		i++;
	}
	return (count);
}

char *ft_strdup(char *src)
{
	int i;
	char *output;

	i = 0;
	while (src[i] && src[i] != ' ' && src[i] != '\t')
		i++;
	output = malloc(i + 1);
	i = 0;
	while (src[i] && src[i] != ' ' && src[i] != '\t')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

char **ft_split_whitespaces(char *str)
{
	int i;
	int x;
	char **output;

	i = 0;
	x = 0;
	output = malloc(sizeof(char*) * (count_words(str) + 1));
	if (output == 0)
		return (0);
	while (str[i])
	{   
		if (str[i] != ' ' && str[i] != '\t')
		{
			output[x] = ft_strdup(str + i);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			i -= 1;
			x++;
		}
		i++;
	}   
	output[x] = 0;
	return (output);
}

void print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int x;
	int count;
	char **tab;

	if (ac >= 2)
	{
		count = count_words(av[1]);
		tab = ft_split_whitespaces(av[1]);
		x = 1;
		while (x < count)
		{
			print(tab[x]);
			ft_putchar(' ');
			x++;
		}
		if (count > 0)
			print(tab[0]);
	}
	write(1, "\n", 1);
	return (0);
}
