/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:59:11 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 01:59:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_size
{
	unsigned short row;
	unsigned short col;
	unsigned short w;
	unsigned short h;
}				t_size;

typedef struct	s_list
{
	char	*str;
	int		len;
	int		selected;
	int		maxlen;
}				t_list;

#endif
