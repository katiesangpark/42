/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validating.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:23:39 by kicausse          #+#    #+#             */
/*   Updated: 2019/03/04 23:05:46 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

static int	is_valid_char(char c)
{
	return (c == ' ' || ft_ishex(c) || c == ',' || c == '-');
}

int			validchars(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (is_valid_char(line[i]) == 0)
			return (0);
	}
	return (1);
}

static int	ft_atoiv2(const char *str)
{
	int result;
	int i;
	int neg;

	i = 0;
	result = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (neg ? -result : result);
}

void		parse_values(char *str, t_point *data)
{
	data->value = ft_atoiv2(str);
	while (*str && *str != ',')
		++str;
	if (*str)
		++str;
	if (*str)
		data->color = ft_atoi_hex(str);
	else
		data->color = DEFAULT_LINE_COLOR;
}

int			count_file_lines(char *filename)
{
	int				fd;
	int				ret;
	unsigned int	count;
	char			buffer[2048 + 1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	count = 0;
	while ((ret = read(fd, buffer, 2048)) > 0)
	{
		buffer[ret] = 0;
		count += ft_ccount(buffer, '\n');
		if ((int)ft_strlen(buffer) != ret
			|| ft_isstrascii(buffer) == 0
			|| count > INT_MAX)
		{
			ret = -1;
			break ;
		}
	}
	close(fd);
	return (ret == -1 ? -1 : count + 1);
}
