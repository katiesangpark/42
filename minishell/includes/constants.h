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

# define SHELL_NAME				"kiloshell"
# define SHELL_VERSION			"0.1"
# define PROMPT 				SHELL_NAME"-"SHELL_VERSION"$> "
# define PROMPT_LENGTH 			(16)
# define PROMPT_COLORED			(0)

# if PROMPT_COLORED==1

# endif

# define CONST_PROCESS_CHILDREN (0)

# define BUILTINS_AMOUNT		(1)

#endif
