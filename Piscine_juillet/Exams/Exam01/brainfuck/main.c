/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:14:46 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:33:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int get_matching_bracket(char *source, int position)
{
	int idx;
	int i;
	int type;
	int counter;

	idx = 0;
	type = source[position] == '[';
	i = type == 1 ? position + 1 : position - 1;
	counter = 0;
	if (type == 1)
	{
		while (source[i])
		{
			if (counter == 0 && source[i] == ']')
				return (i);
			if (source[i] == '[')
				counter++;
			if (source[i] == ']')
				counter--;
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			if (counter == 0 && source[i] == '[')
				return (i);
			if (source[i] == ']')
				counter++;
			if (source[i] == '[')
				counter--;
			i--;
		}
	}
	return (position);
}

void brainfuck(char *octets, char *source)
{
	int i;
	char *ptr;
	ptr = octets;

	i = 0;
	while (source[i])
	{
		if (source[i] == '>')
			ptr++;
		else if (source[i] == '<')
			ptr--;
		else if (source[i] == '+')
			*ptr += 1;
		else if (source[i] == '-')
			*ptr -= 1;
		else if (source[i] == '.')
			write(1, ptr, 1);
		else if (source[i] == '[' && *ptr == 0)
		{
			i = get_matching_bracket(source, i) - 1;
		}
		else if (source[i] == ']' && *ptr != 0)
		{
			i = get_matching_bracket(source, i) - 1;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	char octets[2048];

	i = 0;
	while(i < 2048)
		octets[i++] = 0;
	if (argc == 2)
		brainfuck(octets, argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
