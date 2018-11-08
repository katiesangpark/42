/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:10 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 15:38:10 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fight.h"
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

void	ft_fight(t_perso2 *attacker, t_perso2 *attacked, int atktype)
{
	if (attacker->life == 0 || attacked->life == 0)
		return ;
	if (atktype == KICK)
		attacked->life = CAP(attacked->life - 15);
	else if (atktype == PUNCH)
		attacked->life = CAP(attacked->life - 5);
	else if (atktype == HEADBUTT)
		attacked->life = CAP(attacked->life - 20);
	if (atktype == 0)
		print_attack(attacker->name, attacked->name, "kick");
	else if (atktype == 1)
		print_attack(attacker->name, attacked->name, "punch");
	else if (atktype == 2)
		print_attack(attacker->name, attacked->name, "headbutt");
	if (attacked->life == 0)
		print_dead(attacked->name);
}
