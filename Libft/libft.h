/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *ptr, int value, size_t num);
void			ft_bzero(void *sl, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t num);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *destination, const char *source);
char			*ft_strncpy(char *destination, const char *source, size_t num);
char			*ft_strcat(char *destination, const char *source);
char			*ft_strncat(char *destination, const char *source, size_t num);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char *str, int character);
char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strnstr(const char *s1, const char *s2, size_t length);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_max(int n1, int n2);
int				ft_min(int n1, int n2);
unsigned int	ft_abs(int value);
char			*ft_strtolower(char *string);
char			*ft_strtoupper(char *string);
int				ft_set_bit(int nbr, int idx, char value);
char			ft_get_bit(int nbr, int idx);
void			*ft_print_memory(void *addr, unsigned int size);
void			ft_print_hex(unsigned int value, int length);
char			*ft_strins(char *dest, const char *src, unsigned int pos);
t_list			*ft_lstpush(t_list **begin_list, void *content,
							int content_size);
void			ft_lstdelelem(t_list **alst, t_list *elem);
char			*ft_strjoinfree(char *source, const char *concat);
void			*ft_realloc(void *ptr, size_t size);
int				ft_floor(int min, int value);
int				ft_ceil(int max, int value);

#endif
