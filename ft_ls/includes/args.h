/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:37:41 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 22:37:42 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "args_struct.h"

# define ARGS_H
# define FLAGS ("Ralrt")
# define FLAG_ALL			(1)
# define FLAG_LIST			(2)
# define FLAG_REVERSE		(4)
# define FLAG_RECURSIVE		(8)
# define FLAG_TIME_SORT		(16)

int			validate_parameters(t_args *args, char *str);
int			validate_arguments(t_args *args, int ac, char **av);

#endif
