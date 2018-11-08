/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:56:36 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 18:56:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, int dest_len)
{
	int	i;

	i = 0;
	while (src[i] && i < dest_len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		match_strings(char *s1, const char s2[32])
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i] && s1[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		c_find(const char s1[32], char c)
{
	int	i;

	i = 0;
	while (s1[i] && i < 32)
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
