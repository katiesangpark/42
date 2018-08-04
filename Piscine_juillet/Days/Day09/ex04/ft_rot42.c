/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 00:49:35 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 00:49:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

char	rotation(char c)
{
	if (is_alpha(c) == 1)
	{
		if (c <= 'j')
			c += 'q' - 'a';
		else
			c -= 'k' - 'a';
	}
	else if (is_alpha(c) == 2)
	{
		if (c <= 'J')
			c += 'q' - 'a';
		else
			c -= 'k' - 'a';
	}
	return (c);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = rotation(str[i]);
		i++;
	}
	return (str);
}
