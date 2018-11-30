/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:53:55 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 18:53:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/ft_printf.h"

int main(void)
{
	ft_printf("String is : [%s] Number is : [%x]\n", "test", 0xABCDEF);
	printf("String is : [%s] Number is : [%x]\n", "test", 0xABCDEF);
	return 0;
}