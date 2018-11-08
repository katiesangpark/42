/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:35:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 08:35:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buffer[1];

	if (argc != 2)
	{
		print((argc == 1) ? "File name missing.\n" : "Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buffer, 1) > 0)
		ft_putchar(buffer[0]);
	close(fd);
	return (0);
}
