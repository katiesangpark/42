/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 02:47:23 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 02:47:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structs.h"

int		ft_putchar_stdin(int c);
void	get_window_size(t_size *size);
void	print_with_pad(char *str, int len, int maxlen);
int		remove_list_elem(t_list *list, unsigned int *cursor, int *list_size);

#endif
