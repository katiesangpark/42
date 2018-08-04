/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 02:04:35 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 02:04:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_btree.h"
#include "ex09/ft_btree_rb.h"
#include <stdio.h>
#include <unistd.h>
#define COUNT 5

t_btree	*btree_create_node(void *item);
void    btree_apply_infix(t_btree *root, void (*applyf)(void *));
void    btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void    btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void    btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void    *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int     btree_level_count(t_btree *root);
void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}


void	print_tree(t_btree *tree)
{
	if (tree == 0)
		printf("|");
	else
	{
		printf("%s -> ", tree->item);
		print_tree(tree->left);
		print_tree(tree->right);
	}
}

void    print(void *str)
{
    int i;
    char *s = (char*)str;

    i = 0;
    while (s[i] != '\0')
        i++;
    write(1, s, i);
}

void print2DUtil(t_btree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("(%s\n", root->item);
 
    // Process left child
    print2DUtil(root->left, space);
}

int		main(int argc, char **argv)
{
	t_btree *tree;

    tree = 0;
    for(int i = 1; i < argc; i++)
    {
        if (tree == 0)
            tree = btree_create_node(argv[i]);
        else
            btree_insert_data(&tree, argv[i], &ft_strcmp);
    }

    printf("%d\n", btree_search_item(tree, "Gyeu2", &ft_strcmp));
	print2DUtil(tree, 10);
	return 0;
}