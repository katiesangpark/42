/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 04:12:44 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 04:12:45 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	browse_tree(t_btree *root, int current_level, int *maxlevel)
{
	if (root == 0)
		return ;
	current_level++;
	browse_tree(root->left, current_level, maxlevel);
	if (current_level > *maxlevel)
		*maxlevel = current_level;
	browse_tree(root->right, current_level, maxlevel);
}

int		btree_level_count(t_btree *root)
{
	int level;

	level = 0;
	browse_tree(root, 0, &level);
	return (level);
}
