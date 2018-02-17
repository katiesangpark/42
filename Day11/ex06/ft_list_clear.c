/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcausse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:56:47 by kcausse           #+#    #+#             */
/*   Updated: 2018/02/17 16:56:48 by kcausse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list **begin_list)
{
	t_list *list;
	t_list *tmp;

	list = *begin_list;
	tmp = NULL;
    while (list != NULL)
    {
    	if (list->next != NULL)
        	tmp = list->next;
        else
        	tmp = NULL;
        free(list);
        list = tmp;
    }
	//free(begin_list);
}

t_list    *ft_create_elem(void *data)
{
    t_list *tmp;
    
    if ((tmp = (t_list*)malloc(sizeof(t_list))) == NULL)
        return (NULL);
    tmp->next = (NULL);
    tmp->data = data;
    return (tmp);
}


void ft_list_push_front(t_list **begin_list, char *data)
{
    if (*begin_list == NULL)
        *begin_list = ft_create_elem(data);
    else
    {
        t_list *list;
        
        list = ft_create_elem(data);
        list->next = *begin_list;
        *begin_list = list;
    }
}


int ft_list_size(t_list *begin_list)
{
    int i;
    t_list *list;
    
    if (begin_list->next == NULL)
        return (1);
    i = 2;
    list = begin_list->next;
    while (list->next != NULL && i++)
        list = list->next;
    return (i);
}

int main(int argc, char **argv)
{
    t_list *list;
    t_list *ozo;
    
    list = ft_create_elem("rfgfhfhgfhfgfghgfhgfhg");
    ozo = list;
    ft_list_push_front(&list, "test");
    ft_list_push_front(&list, "1");
    ft_list_push_front(&list, "2");
    ft_list_push_front(&list, "3");
    ft_list_push_front(&list, "4");
    ft_list_push_front(&list, "5");
    
    ft_list_clear(&list);
    printf("%d\n", ft_list_size(list));
    while (list->next != NULL)
    {
        printf("--%s\n", list->data);
        list = list->next;
    }
    printf("--%s\n", list->data);
    return 0;
}