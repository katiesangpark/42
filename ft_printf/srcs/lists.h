/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:17:42 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 20:17:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct	s_specifier
{
	char	option;
	char	*flag;
	struct s_specifier	*next;
}				t_specifier;

t_specifier			*spec_lst_new(char option, char *flag);
t_specifier			*spec_lst_push(t_specifier **begin_list, char option, char *flag);
void				spec_lst_clear(t_specifier *lst);

#endif
