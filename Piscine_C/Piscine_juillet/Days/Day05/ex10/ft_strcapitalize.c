/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:58:56 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 14:58:57 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_next_char_capitalized(char c)
{
	if (c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

char	capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char	uncapitalize(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i + 1] = uncapitalize(str[i + 1]);
		if (i == 0)
			str[i] = capitalize(str[i]);
		else if (is_next_char_capitalized(str[i]))
			str[i + 1] = capitalize(str[i + 1]);
		i++;
	}
	return (str);
}
