/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:55:28 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 03:55:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void	*tmp;

	if (root == 0 || cmpf == 0)
		return (0);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp != 0)
		return (tmp);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	return (tmp);
}
