/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:18:47 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:18:48 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define SHELL_NAME				"kil0shell"
# define SHELL_VERSION			"0.1"
# define DIR_COLOR				"\033[38;5;49m"
# define PROMPT_BASE			SHELL_NAME"-"SHELL_VERSION
# define PROMPT_END 			"-$> "
# define PROMPT_END_COLOR 		"-\033[38;5;9m$>\033[0m "
# define PROMPT_BASE_COLOR		"\033[38;5;80m"PROMPT_BASE
# define PROMPT 				PROMPT_BASE PROMPT_END
# define PROMPT_SHLVL			PROMPT_BASE"-%d"PROMPT_END
# define PROMPT_COLOR 			PROMPT_BASE_COLOR PROMPT_END_COLOR
# define PROMPT_SHLVL_COLOR		PROMPT_BASE_COLOR"-%d\033[0m"PROMPT_END_COLOR

# define BUILTINS_AMOUNT		(16)

# define BUF_SIZE				(1024)

# define LOG_FILE				"/Users/kicausse/.kil0shell_history"

# define SHRC_FILE				"/Users/kicausse/.kil0shellrc"

#endif
