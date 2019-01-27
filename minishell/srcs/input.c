/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:17:46 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/24 02:17:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "constants.h"
#include "utils.h"
#include <termios.h>

void	config_shell_input(t_shell *shell, int mode)
{
	struct termios	termios_p;

	if (mode == 0)
		tcgetattr(0, &(shell->termios_p));
	if (mode == 0 || mode == 1)
	{
		ft_memcpy(&termios_p, &(shell->termios_p), sizeof(struct termios));
		termios_p.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(0, 0, &termios_p);
	}
}

void	move_cursor(unsigned int *x, unsigned int max_x, int code)
{
	if (code == INPUT_RIGHT && *x < max_x)
	{
		*x += 1;
		ft_putstr("\x1B\x5B\x43");
	}
	else if (code == INPUT_LEFT && *x > 0)
	{
		*x -= 1;
		ft_putstr("\x1B\x5B\x44");
	}
}

void	delete_char(char *buffer, unsigned int *cursor_x, unsigned int *offset)
{
	*cursor_x -= 1;
	*offset -= 1;
	ft_strcut(buffer, *cursor_x, *cursor_x + 1);
	ft_putstr("\b \b");
	ft_putstr(buffer + *cursor_x);
	ft_print_char(' ', *offset - *cursor_x);
	ft_print_char('\b', *offset - *cursor_x);
	ft_print_char('\b', *offset - *cursor_x);
}

int		read_input(t_shell *shell, unsigned int bufsize)
{
	unsigned int	offset;
	unsigned int	cursor_x;
	char			buf;
	unsigned int	escapemode;

	ft_bzero(shell->buf, bufsize);
	offset = 0;
	cursor_x = 0;
	while (read(0, &buf, 1) && buf != '\n')
	{
		if (offset + 1 >= bufsize
			&& (shell->buf = ft_realloc(shell->buf, bufsize *= 2)) == NULL)
			return (0);
		if (buf == 127 && cursor_x > 0 && offset > 0)
			delete_char(shell->buf, &cursor_x, &offset);
		else if (buf == 27)
			escapemode = 1;
		else if (buf == 91)
			escapemode = 2;
		else if (escapemode == 2 && !(escapemode = 0))
			move_cursor(&cursor_x, offset, buf);
		else if (ft_isprint(buf))
		{
			ft_strnins(shell->buf, &buf, 1, cursor_x++);
			ft_putstr(shell->buf + cursor_x - 1);
			ft_print_char('\b', ++offset - cursor_x);
		}
	}
	ft_putchar('\n');
	log_input(shell);
	return (1);
}
