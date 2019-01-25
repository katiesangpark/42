/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:54:48 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 22:54:48 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "shell.h"
#include "commands.h"
#include "constants.h"
#include "parsing.h"

void	exec_line_command(t_shell *shell, char *cmd)
{
	char	**args;

	if (ft_strlen(cmd) >= BUF_SIZE)
		if ((shell->buf = ft_realloc(shell->buf, ft_strlen(cmd))) == NULL)
			return ;
	ft_strcpy(shell->buf, cmd);
	if ((args = parse_input(shell->buf, shell)) == NULL)
		return ;
	exec_command(shell, args);
	ft_free_tab(args);
}

void	exec_file(t_shell *shell, char *file)
{
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, "source: error: could not read file %s\n", file);
		return ;
	}
	buf = NULL;
	while (get_next_line(fd, &buf) == 1)
	{
		exec_line_command(shell, buf);
		ft_strdel(&buf);
	}
	return ;
	ft_strdel(&buf);
	close(fd);
}
