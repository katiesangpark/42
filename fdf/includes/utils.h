/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:56:46 by kicausse          #+#    #+#             */
/*   Updated: 2019/03/01 19:56:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <string.h>

void	free_tab_len(char **tab, int len);
int		get_data_count(char *line);
void	free_tab(char **tab);
char	*write_nbr_to_buffer(char *buffer, long nbr, size_t bufsize);

#endif
