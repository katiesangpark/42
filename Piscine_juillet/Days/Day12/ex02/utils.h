/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:04:32 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/11 00:04:33 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFSIZE (256)
# include <unistd.h>
# include <fcntl.h>

char	*ft_concat_params(int argc, char **argv);
char	*get_file(char *filename);
int		is_number_valid(char *str);
int		ft_atoi_inv(char *str);
int		ft_strlen(char *str);
int		file_exists(char *filename);
int		get_offset(char **argv, int argc, int *index, int *error);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	print(char *str);
void	print_error_message(int errcode, char *str);
void	concat_strings(char **dest, char *src, int amount);

#endif
