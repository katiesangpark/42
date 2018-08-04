/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:40:13 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 18:55:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char *ft_strdup(char *str)
{
	int i;
	char *output;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	output = malloc(i + 1);
	if (output == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = 0;
	return (output);
}

int count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != 0)
			count++;
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] != 0)
			i++;
	}
	return (count + 1);
}

void printstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int main(int argc, char **argv)
{
	char **tab;
	char *str;
	int x;
	int i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	tab = malloc(sizeof(char*) * count_words(argv[1]));
	x = 0;
	i = 0;
	str = argv[1];
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != 0)
			tab[x++] = ft_strdup(str + i);
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] != 0)
			i++;
	}
	tab[x] = 0;
	if (tab[0] != 0)
	{
		x = 1;
		while (tab[x])
		{
			printstr(tab[x]);
			write(1, " ", 1);
			x++;
		}
		printstr(tab[0]);
	}
	write(1, "\n", 1);
	return (0);
}
