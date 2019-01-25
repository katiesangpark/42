/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:17:44 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:17:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "shell.h"

typedef struct	s_builtin
{
	char	*command;
	void	(*func)(t_shell *shell, char **args);
}				t_builtin;

void			b_alias(t_shell *shell, char **args);
void			b_alias_list(t_shell *shell, char **args);
void			b_cd(t_shell *shell, char **args);
void			b_doc(t_shell *shell, char **args);
void			b_echo(t_shell *shell, char **args);
void			b_env(t_shell *shell, char **args);
void			b_export(t_shell *shell, char **args);
void			b_exit(t_shell *shell, char **args);
void			b_help(t_shell *shell, char **args);
void			b_history(t_shell *shell, char **args);
void			b_setenv(t_shell *shell, char **args);
void			b_unsetenv(t_shell *shell, char **args);

int				exec_builtin(char *command, char **args, t_shell *shell);
int				exec_command(t_shell *shell, char **args);

#endif
