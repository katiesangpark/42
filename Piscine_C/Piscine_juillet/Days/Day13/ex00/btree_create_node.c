/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:06:03 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 02:06:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *output;

	output = malloc(sizeof(t_btree));
	if (output != NULL)
	{
		output->left = 0;
		output->right = 0;
		output->item = item;
	}
	return (output);
}
