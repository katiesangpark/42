/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:26:26 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/08 06:26:26 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE (256)
# define ERR_ALLOC_FAIL (-2)
# define ERR_READ_FAIL (-1)
# define ERR_FILE_END (0)
# define ERR_SUCCESS (1)

int	get_next_line(const int fd, char **line);

#endif
