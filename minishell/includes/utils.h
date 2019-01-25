/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:20:19 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:20:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "shell.h"

int		exists(char *path);
int		is_dir(char *path);
int		is_executable(char *path);
char	*concat_env_string(char *name, char *value);
char	*get_cwd(char *path);

#endif
