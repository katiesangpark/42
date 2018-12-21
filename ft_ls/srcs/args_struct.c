/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 06:30:25 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 06:30:25 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "args_struct.h"

t_args	*new_args(void)
{
	t_args	*new;

	if ((new = (t_args*)ft_memalloc(sizeof(t_args))) == NULL)
		return (NULL);
	return (new);
}
