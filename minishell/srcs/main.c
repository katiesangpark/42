/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:49:33 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/22 15:49:33 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include "parsing.h"
#include "constants.h"
#include "builtins.h"
#include "libft.h"

int		exists(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (S_ISREG(f_stat.st_mode));
}

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

	path += 5;
	cmdlen = ft_strlen(command);
	while (*path != '\0')
	{
		i = 0;
		while (path[i] != '\0' && path[i] != ':')
			i++;
		if (!(final_command = build_command(path, command, i, cmdlen)))
			return (NULL);
		if (exists(final_command))
			return (final_command);
		ft_strdel(&final_command);
		if (path[i] == '\0')
			break ;
		path += i + 1;
	}
	return (command);
}

void	exec_command(char *path, char **args, char **env)
{
	pid_t	process_id;
	char	*command;

	if (exec_builtin(args[0], args) != 0)
		return ;
	if ((command = find_command(args[0], path)) == NULL)
		return ;
	if (command == args[0])
	{
		ft_printf(SHELL_NAME": command not found: %s\n", command);
		return ;
	}
	process_id = fork();
	if (process_id == CONST_PROCESS_CHILDREN)
		execve(command, args, env);
	else
	{
		if (command != args[0])
			ft_strdel(&command);
		wait(0);
	}
}

char	*get_path(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 4) == 0)
			return (env[i]);
		i++;
	}
	return ("");
}

int		main(int ac, char **av, char **env)
{
	char	**args;
	char	buf[256];
	int		offset;
	char	*path;

	(void)av;
	(void)ac;
	path = get_path(env);
	while (1)
	{
		write(1, PROMPT, PROMPT_LENGTH);
		offset = 0;
		read(0, buf, 1);
		while (buf[offset++] != '\n')
			read(0, buf + offset, 1);
		buf[offset - 1] = '\0';
		args = parse_input(buf);
		exec_command(path, args, env);
	}
	return (0);
}
