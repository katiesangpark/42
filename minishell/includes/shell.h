/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:59:08 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 22:59:09 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <termios.h>

typedef struct	s_shell
{
	char			**env;
	char			**alias;
	char			*pwd;
	char			*buf;
	int				shlvl;
	int				show_shlvl;
	int				no_log;
	int				color;
	int				showdir;
	int				running_command;
	int				no_shrc;
	struct termios	termios_p;
}				t_shell;

char			**copy_env(char **env, char *newelem);
char			*get_env_var(char *name, char **env);
void			set_env_var(char *name, char *value, t_shell *shell);
void			remove_env_var(char *name, char **env);

void			set_default_env(t_shell *shell, char **env);

void			log_input(t_shell *shell);

void			exec_shrc(t_shell *shell);

void			write_prompt(t_shell *shell);

void			signal_init(t_shell *shell);

#endif
