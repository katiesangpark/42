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
# define PROMPT 				SHELL_NAME"-"SHELL_VERSION"$> "
# define PROMPT_LENGTH 			(16)
# define PROMPT_SHLVL			SHELL_NAME"-"SHELL_VERSION"-%d$> "

# define BUILTINS_AMOUNT		(13)

# define BUF_SIZE				(1024)

# define LOG_INPUT				(1)
# define LOG_FILE				"/Users/kicausse/.kil0shell_history"

#endif
