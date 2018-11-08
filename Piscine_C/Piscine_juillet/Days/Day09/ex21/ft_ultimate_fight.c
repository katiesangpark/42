/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_fight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:10 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 15:38:10 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimate_fight.h"
#include <unistd.h>

void	print(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_dead(char *attacked)
{
	print(attacked);
	print(" is dead.\n");
}

void	print_attack(char *attacker, char *attacked, char *atktype)
{
	print(attacker);
	print(" does a judo ");
	print(atktype);
	print(" on ");
	print(attacked);
	print(".\n");
}

void	ft_fight(t_perso2 *attacker, t_perso2 *attacked, char *atktype)
{
	if (attacker->life == 0 || attacked->life == 0)
		return ;
	attacked->life = CAP(attacked->life - atktype);
	if (attacked->life == 0)
		print_dead(attacked->name);
	print_attack(attacker->name, attacked->name, atktype);
}
