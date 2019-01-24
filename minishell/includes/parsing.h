/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:15:43 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:15:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "shell.h"

void	read_input(char *buf);

int		look_for_char(char *dest, char c);
void	ignore_chars(char **dest, char *charset);
int		quote_match(char *input, unsigned int *e, unsigned int *quote);

char	**parse_input(char *input, t_shell *shell);

#endif
