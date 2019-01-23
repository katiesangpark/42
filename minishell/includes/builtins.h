/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:29:42 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:29:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct	s_builtin
{
	char	*command;
	void	(*func)(char **args);
}				t_builtin;

int				exec_builtin(char *command, char **args);

#endif
