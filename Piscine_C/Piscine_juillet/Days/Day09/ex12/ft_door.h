/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 04:42:31 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 04:42:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>
# define TRUE (1)
# define OPEN (1)
# define CLOSE (0)

typedef int		t_bool;

typedef struct	s_door
{
	t_bool	state;
}				t_door;

#endif
