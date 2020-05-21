/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:13:34 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 22:51:12 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#define FLAGS " ~-+0123456789#.lh=&"

/*
** le flag '~' correspond a 0 seul
** le flag '=' correspond a un nombre negatif
** le flag '&' correspond a 0 seul sans valeur derriere
*/

char			*g_ptab;
int				g_terminal;

typedef struct	s_map
{
	char		key;
	int			present;
}				t_map;

/*
** (void *var) est la variable recu par va_arg
** (const char *c) est le pointer sur le parametre dans la string
*/
int				(*g_p[22])(void *var, void *charpointer, const char *c);

/* FONCTION TEMPORAIRE UTILISE POUR LE DEBUGAGE */
void			ft_printmap(t_map *map);

/*
** w_ft_put_long.c
*/
int				w_ft_put_long(void *nb, void *charpointer, const char *c);
int				ft_llflag_erro(t_map *map);
int				ft_llputspace(char *nombre, const char *c, t_map *map);
int				ft_put_llprecision(char *nombre, const char *c, t_map *map);
int				ft_put_flag(char *nombre, const char *c, t_map *map);
int				precision_len(char *nombre, const char *c, t_map *map);
char			ft_float_param(char *str);
void			ft_put_llconv(char *nombre, t_map *map);
void			ft_init_tab(void);
void			ft_llprint_space(int nbr, char *nombre, t_map *map);
void			ft_llprint_space(int nbr, char *nombre, t_map *map);

int				ft_printf(const char *format, ...);
int				ft_verif_arg(char c);
int				ft_verif_flag(char c);
int				ft_minfield(const char *c, void *pointer, void *charpointer, int compute);
int				ft_found_minus(const char *c, int y);
int				ft_space_digit(void *pointer, void *charpointer, const char *c);
int				ft_find_cara(const char *c, int i, char cara);
int				ft_nbrofzero(const char *c, void *pointer, void *charpointer, int i);
int				ft_isfloat(char *str, va_list vlst);
int				find_field_size(const char *c);
int				how_much_digit(long double nbr);
int				ft_find_flag(char *str, char flag);
int				ft_pass_flags(char *str);
void			ft_putlongnbr(void *nb);
void			ft_print_prefix(t_map *map);

t_map			*ft_create_map(const char *c, void *pointer);
t_map			*ft_nbr_is_negatif(void *nbr, t_map *map);
int				ft_end_map(t_map *map);
int				ft_flag_presence(char *str, t_map *map);
int				ft_all_flag_presence(char *str, t_map *map);

int				nbrofspace(const char *c, void *pointer, void *charpointer, t_map *map);
int				ft_putspace(void *cara, void *charpointer, const char *c, t_map *map);
int				ft_put_precision(const char *c, void *pointer, t_map *map);
int				ft_is_not_point(char *c);
char			ft_find_key(char *str);
void			ft_put_conversion(char *c, void *pointer, t_map *map);
void			ft_print_pointer(void *pointer, t_map *map);

int				w_ft_putconverted(void *nb, void *charpointer, const char *c);
int				mp_unsinteger_len(const char *c, void *pointer, t_map *map);
int				ft_unside_len(const char *c, void *pointer, t_map *map);

/*
** ft_give_conversion.c
*/
char			*ft_put_precisionstr(char *str, const char *c, t_map *map);
char			*ft_give_conversion(char *str, t_map *map, const char *c);
int				ft_false_precision(char *c);
int				ft_prec_0xxo(char *c, t_map *map);

/*
** len_function.c
*/
int				mp_pointer_len(const char *c, void *charpointer, t_map *map);
int				mp_integer_len(const char *c, void *pointer, t_map *map);
int				ft_size_conversion(const char *c, void *pointer, void *charpointer, t_map *map);
int				ft_lenpointer(const char *c, void *charpointer, t_map *map);
int				ft_give_only_len(const char *c, void *pointer, void *charpointer, t_map *map);
int				ft_octal_len(const char *c, void *pointer, t_map *map);
int				map_checker(char flag, t_map *map);
int				mp_octal_len(const char *c, void *pointer, t_map *map);

/*
** ft_find_cara
*/
char			ft_strmutiplechr(char *str, char *to_find);
char			ft_find_param(char *str);
int				ft_zero_discovery(char *str);

int				find_precision(const char *c);
int				w_ft_float(void *nbr, void *charpointer, const char *c);
int				w_ft_putnbr(void *nbr, void *charpointer, const char *c);
int				w_ft_putunbr(void *nbr, void *charpointer, const char *c);
int				w_ft_putstr(void *str, void *charpointer, const char *c);
int				w_ft_putchar(void *cara, void *charpointer, const char *c);
int				w_ft_putpointer(void *nb, void *charpointer, const char *c);
int				w_ft_zero_f(void *pointer, void *charpointer, const char *c);
int				w_ft_plus_f(void *pointer, void *charpointer, const char *c);
int				abs_val(int x);
int				w_ft_size_fields(void *pointer, void *charpointer, const char *c);
int				w_ft_float(void *nbr, void *charpointer, const char *c);
int				w_ft_moins_f(void *pointer, void *charpointer, const char *c);
int				w_ft_diese_f(void *pointer, void *charpointer, const char *c);
int				w_ft_space_f(void *pointer, void *charpointer, const char *c);
int				w_ft_spacebefore_f(void *pointer, void* charpointer, const char *c);
int				w_ft_special_f(void *pointer, void *charpointer, const char *c);
int				ft_analyze(long double nbr);
int				w_ft_put_z(void *pointer, void *charpointer, const char *c);
int				w_ft_binary(void *pointer, void *charpointer, const char *c);
void			float_itoa(long double nbr, const char *c);
void			ft_putstr_f(char const *s);

/* Utility */
int				treat3(const char *c, int *i, void *pointer, const char *save_pos);
void			ft_putcount(char cara);
int				how_many_nbr(char const *c);
int				is_zeroneg(float f);
int				is_special(long double nbr);

#endif