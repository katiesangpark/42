/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 15:38:05 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H
# define KICK (0)
# define PUNCH (1)
# define HEADBUTT (2)
# define CAP(nbr) (nbr > 0 ? nbr : 0)

typedef struct	s_perso2
{
	char	*name;
	float	life;
	int		age;
	int		profession;
}				t_perso2;

#endif
