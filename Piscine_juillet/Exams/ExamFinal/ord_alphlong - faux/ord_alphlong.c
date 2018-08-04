/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:18:43 by exam              #+#    #+#             */
/*   Updated: 2018/07/27 11:56:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *ft_strdup(char *str)
{
	char *out;
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	out = malloc(i + 1);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

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
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		else
			i++;
	}
	return (count);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char tomin(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;
	char c;
	char c2;

	i = 0;
	while (s1[i] && s2[i])
	{
		c = tomin(s1[i]);
		c2 = tomin(s2[i]);
		if (c >= 'a' && c <= 'z' && c2 >= 'a' && c2 <= 'z' && c != c2)
			return (c - c2);
		i++;
	}
	return (0);
}

void sort_words(char **word)
{
	char *tmp;
	int i;
	int length;

	length = 0;
	while (word[length])
		length++;
	i = 0;
	while (i < length - 1)
	{
		while (ft_strcmp(word[i], word[i + 1]) > 0)
		{
			tmp = word[i];
			word[i] = word[i + 1];
			word[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

char **split(char *str)
{
	char **out;
	int word_amount;
	int x;
	int i;

	word_amount = count_words(str) + 1;
	out = malloc(sizeof(char*) * word_amount);
	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			out[x++] = ft_strdup(str + i);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
		else
			i++;
	}
	out[x] = 0;
	return (out);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int main(int ac, char **av)
{
	int x;
	int len;
	int maxlen;
	int p;
	char **words;

	if (ac == 2)
	{
		words = split(av[1]);
		maxlen = 0;
		x = 0;
		while (words[x])
		{
			len = ft_strlen(words[x]);
			if (len > maxlen)
				maxlen = len;
			x++;
		}
		sort_words(words);
		len = 1;
		while (len <= maxlen)
		{
			x = 0;
			p = 0;
			while (words[x])
			{
				if (ft_strlen(words[x]) == len)
				{
					if (p != 0)
						ft_putchar(' ');
					ft_putstr(words[x]);
					p = 1;
				}
				x++;
			}
			if (p)
				ft_putchar('\n');
			len++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
