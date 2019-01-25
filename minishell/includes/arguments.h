/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:39:12 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 01:39:12 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

int		parse_arguments(int ac, char **av);
int		get_arg_letter(char c, int ac, char **av);
int		get_arg(char *arg, int ac, char **av);

#endif
