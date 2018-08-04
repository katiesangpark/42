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
int		ft_strlen(char *str);
int		file_exists(char *filename);
int		get_option(int argc, char **argv, int *index);
int		ft_memcmp(unsigned char *s1, unsigned char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
void	print(char *str);
void	print_error_message(int errcode, char *str);
void	concat_strings(char **dest, char *src, int amount);
void	*ft_print_memory(void *addr, unsigned int size, int option);
void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr, int option);
void	print_hex(unsigned int value, int length);
void	print_asterisk(int *asterisk);

#endif
