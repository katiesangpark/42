/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 12:05:47 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 12:05:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		end;
	int		i;
	char	tmp;

	end = 0;
	while (str[end])
		end++;
	end--;
	i = 0;
	while (i <= end / 2)
	{
		tmp = str[i];
		str[i] = str[end - i];
		str[end - i] = tmp;
		i++;
	}
	return (str);
}
