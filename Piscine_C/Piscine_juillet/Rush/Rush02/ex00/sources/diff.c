/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pisousa <pisousa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:43:48 by pisousa           #+#    #+#             */
/*   Updated: 2018/07/22 13:43:56 by pisousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_char(char c)
{
	return (!(c >= 0 && c <= 32) && c != 127);
}

int		space_match(char c1, char c2)
{
	return ((c1 == ' ' && c2 == ' ') || (c1 != ' ' && c2 != ' '));
}

int		char_match(char c1, char c2)
{
	return ((is_char(c1) && is_char(c2)) || (!is_char(c1) && !is_char(c2)));
}

int		split_line(char *to_split)
{
	int	i;

	i = 0;
	while (to_split[i] != '\0' && to_split[i] != '\n')
	{
		if (is_char(to_split[i]))
			return (-1);
		i++;
	}
	return (i);
}

int		match(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	else if (s1[0] == '\n' && s2[0] != '\n')
	{
		if (split_line(s2) == -1)
			return (0);
		return (match(s1 + 1, s2 + split_line(s2) + 1));
	}
	else if (s1[0] != '\n' && s2[0] == '\n')
	{
		if (split_line(s1) == -1)
			return (0);
		return (match(s1 + 1 + split_line(s1), s2 + 1));
	}
	else if (!(char_match(s1[0], s2[0]) && space_match(s1[0], s2[0])))
		return (0);
	return (match(s1 + 1, s2 + 1));
}
