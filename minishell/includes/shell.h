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

typedef struct	s_shell
{
	char	*path;
	char	*pwd;
	int		shlvl;
	char	**env;
	char	*buf;
}				t_shell;

void			free_env(char **env);
char			**copy_env(char **env, char *newelem);
char			*get_env_var(char *name, char **env);
void			set_env_var(char *name, char *value, t_shell *env);
void			remove_env_var(char *name, char **env);

#endif
