/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:16:47 by saouas            #+#    #+#             */
/*   Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 128
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

size_t					ft_strlen(const char *str);
long long int			ft_ullatoi(const char *str);
void					ft_putullnbr(unsigned long long nbr);
char					*ft_strdup(const char *s1);
int						ft_atoi(const char *str);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_strcat(char *dest, const char *src);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strncpy(char *dest, const char *src, size_t len);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
char					*ft_strstr(const char *str, const char *to_find);
char					*ft_strnstr(const char *str, const char *to_find,
	size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putnbr(int nb);
void					ft_putunbr(unsigned int nb);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnbr_fd(int nb, int fd);
void					ft_putendl_fd(char const *s, int fd);
char					*ft_itoa(int nb);
char					*ft_ulong_itoa(unsigned long nb);
char					**ft_strsplit(char const *s, char c);
char					*ft_strtrim(char const *str);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s, unsigned int start,
	size_t len);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2,
	size_t n);
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
char					*ft_strmap(char const *s, char (*f)(char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_striter(char *s, void (*f)(char *));
void					ft_strclr(char *s);
void					ft_strdel(char **as);
char					*ft_strnew(size_t size);
void					ft_memdel(void	**ap);
void					*ft_memalloc(size_t size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
	void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int						ft_isblank(int c);
int						ft_str_is_alpha(char *str);
int						ft_str_is_printable(char *str);
int						ft_str_is_numeric(char *str);
int						ft_str_is_lowercase(char *str);
int						ft_str_is_uppercase(char *str);
char					*ft_strndup(const char *s, size_t n);
int						get_next_line(const int fd, char **line);
char					*ft_strjoin_free(char const *s1,
						char const *s2, int string);
void					ft_print_words_tables(char **tab);
char					*ft_strdjoin(char *s1, char *s2);
int						ft_nbrlen(int n);
long long int			ft_pow(int x, unsigned int y);
int						ft_isthischar(char *str, char c);
char					*ft_realloc(char *ptr, long long int newsize);
void					ft_reverse_str(char *str, int len);
long long int			ft_atoi_base(char *str, char *base);
char					*ft_convert_base_finale(char *nbr, char *base_to);
int						get_nb(char c, char *base);
int						abs_val(int x);
char					*ft_litoa(long long int nb);
unsigned long long int	atoul_base(char *str, char *base);
char					*ft_lutoa(unsigned long long int nb);
char					*ft_ul_convert_base_finale(char *nbr, char *base_to);
void					ft_putnbr_sizet(size_t nbr);
int						w_ft_str_color(void *str, void *charpointer, const char *c);
#endif
