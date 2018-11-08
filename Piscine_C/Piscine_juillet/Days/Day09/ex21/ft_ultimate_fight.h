/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 15:38:05 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ULTIMATE_FIGHT_H
# define FT_ULTIMATE_FIGHT_H
# define KICK2 ("chop ni")
# define PUNCH ("punch")
# define KICK8 ("chop hachi")
# define KICK7 ("chop shichi")
# define KICK4 ("chop shi")
# define KICK10 ("chop ju")
# define KICK12 ("chop sen")
# define KICK9 ("chop ku")
# define KICK5 ("chop go")
# define KICK1 ("chop ichi")
# define KICK6 ("chop roku")
# define KICK ("kick")
# define KICK3 ("chop san")
# define KICK11 ("chop hyaku")
# define HEADBUTT ("headbutt")
# define CAP(nbr) (nbr > 0 ? nbr : 0)

typedef struct	s_perso2
{
	char	*name;
	float	life;
	int		age;
	int		profession;
}				t_perso2;

typedef struct	s_atktype
{
	int		damage;
	char	*text;
}				t_atktype;

static struct s_atktype	g_atk[] = {
	{3, "chop ni"},
	{5, "punch"},
	{6, "chop hachi"},
 	{8, "chop shichi"},
	{9, "chop shi"},
	{9, "chop ju"},
	{10, "chop sen"},
	{11, "chop ku"},
	{11, "chop go"},
	{13, "chop ichi"},
	{13, "chop roku"},
	{15, "kick"},
	{18, "chop san"},
	{18, "chop hyaku"},
	{20, "headbutt"},
};

#endif
