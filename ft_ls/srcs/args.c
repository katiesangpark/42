/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:43:30 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 22:43:30 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "libft.h"
#include "ft_ls.h"

int		validate_parameters(t_args *args, char *str)
{
	int		i;

	if (str == 0 || *str == '\0')
		return (0);
	i = 0;
	while (FLAGS[i] != '\0')
	{
		if (*str == FLAGS[i])
		{
			args->flags |= (1 << i);
			return (validate_parameters(args, str + 1));
		}
		i++;
	}
	return (*str);
}

void	complete_arguments(t_args *args)
{
	if (args->flags & FLAG_NUMERIC_ID || args->flags & FLAG_OMIT_GID)
		args->flags |= FLAG_LIST;
	if (args->flags & FLAG_NON_SORT)
		args->flags |= FLAG_ALL;
}

int		validate_arguments(t_args *args, int ac, char **av)
{
	int			i;
	char		tmp;
	int			nonargs;
	t_folder	*newfolder;

	i = 0;
	nonargs = 0;
	while (++i < ac)
	{
		if (nonargs == 0 && av[i][0] == '-' && av[i][1] != '\0')
		{
			if ((tmp = validate_parameters(args, av[i] + 1)) == 0)
				continue ;
			ft_printf("ft_ls: illegal option -- %c\n", tmp);
			return (ERR_INVALID_ARG);
		}
		if ((newfolder = folder_lst_new(av[i], ft_strdup(""))) == NULL)
			return (ERR_MALLOC_FAIL);
		folder_lst_push(&args->search_folder, newfolder);
		nonargs = 1;
	}
	if (args->search_folder == NULL)
		args->search_folder = folder_lst_new("./", ft_strdup(""));
	return (args->search_folder == NULL ? ERR_MALLOC_FAIL : ERR_NO_ERR);
}
