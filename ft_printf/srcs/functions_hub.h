/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_hub.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:12:43 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/30 02:12:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HUB_H
# define FUNCTIONS_HUB_H
# include "lists.h"

typedef struct	s_opp
{
	char	operator;
	void	(*function)(int, t_specifier*);
}				t_opp;

void			int_handling(int value, t_specifier *spec);

void			ft_putinbr(int n);
void			ft_putuinbr(unsigned int n);
void			ft_putnbr_octal(unsigned int n);
void			ft_print_hex2(unsigned int value, char *base);

#endif
