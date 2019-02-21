/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:49:15 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 04:49:15 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "structs.h"

void	print_selected(t_list *list);
void	get_list_info(int *maxlen, char **av, t_list *list);
void	print_list(t_list *list, unsigned int cursor, const int maxlen);
void	print_from_static(t_list *list, unsigned int *cursor, int maxlen);

#endif
