/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:40:27 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 06:40:27 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "structs.h"
# include <term.h>

void	clear_current_screen(void);
void	init_terminal(struct termios *termios_p);
void	reset_terminal(struct termios *termios_p);
int		handle_input(unsigned int *cursor, t_list *list, int *list_size);

void	signal_handler(int signo);

#endif
