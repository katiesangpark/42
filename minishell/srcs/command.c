/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:17:19 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:17:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "utils.h"
#include "libft.h"
#include "commands.h"
#include "constants.h"

char	*build_command(char *prefix, char *command, unsigned int prefix_len,
						unsigned int cmdlen)
{
	char	*output;

	if ((output = ft_strnew(prefix_len + cmdlen + 1)) == NULL)
		return (NULL);
	ft_memcpy(output, prefix, prefix_len);
	output[prefix_len] = '/';
	ft_memcpy(output + prefix_len + 1, command, cmdlen + 1);
	return (output);
}

char	*find_command(char *command, char *path)
{
	unsigned int	i;
	unsigned int	cmdlen;
	char			*final_command;

	if (ft_cfind(command, '/') != -1)
		return (exists(command) ? command : "");
	cmdlen = ft_strlen(command);
	while (*path != '\0')
	{
		i = 0;
		while (path[i] != '\0' && path[i] != ':')
			++i;
		if (!(final_command = build_command(path, command, i, cmdlen)))
			return (NULL);
		if (exists(final_command))
			return (final_command);
		ft_strdel(&final_command);
		if (path[i] == '\0')
			break ;
		path += i + 1;
	}
	return ("");
}

int		exec_command(t_shell *shell, char **args)
{
	pid_t	process_id;
	char	*command;

	if (args == NULL || *args == NULL || **args == '\0'
		|| exec_builtin(args[0], args, shell) != -1)
		return (0);
	if ((command = find_command(args[0], shell->path)) == NULL)
		return (0);
	if (command[0] == '\0')
	{
		ft_printf_fd(2, SHELL_NAME": command not found: %s\n", args[0]);
		return (0);
	}
	process_id = fork();
	if (process_id == 0)
		return (execve(command, args, shell->env));
	else
	{
		if (command != args[0])
			ft_strdel(&command);
		shell->running_command = 1;
		wait(0);
		shell->running_command = 0;
	}
	return (0);
}
