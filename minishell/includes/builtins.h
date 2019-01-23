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

void			b_exit(char **args);
void			b_cd(char **args);

int				exec_builtin(char *command, char **args);
void			exec_command(char *path, char **args, char **env);

#endif
