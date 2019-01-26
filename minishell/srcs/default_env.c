/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 21:09:27 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/26 21:09:28 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "constants.h"

void	set_default_env(t_shell *shell, char **env)
{
	if (get_env_var("PATH", env) == NULL)
		set_env_var("PATH", DEFAULT_PATH, shell);
}
