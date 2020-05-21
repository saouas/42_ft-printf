/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:58:07 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 19:09:55 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** all the function do something about minimum field size
*/

int			ft_len_conversion(const char *c, void *pointer, t_map *map)
{
	char	key;
	int		len;

	key = map[ft_end_map(map)].key;
	if (key == 'x' || key == 'X')
		len = ft_lenpointer(c, pointer, map);
	else if (key == 'o')
		len = ft_octal_len(c, pointer, map);
	else if (key == 'u')
		len = ft_unside_len(c, pointer, map);
	else
		len = ft_nbrlen(*((int *)pointer));
	return (len);
}

/*
** print des 0 par rapport a la taille de la precision
** return la taille que prend la precision
*/
int			ft_put_precision(const char *c, void *pointer, t_map *map)
{
	int		precision;
	int		len;
	int		i;
	char	key;

	i = 0;
	key = map[ft_end_map(map)].key;
	len = ft_len_conversion(c, pointer, map);
	precision = find_precision(c);
	if (ft_flag_presence("#", map) == 1 && (*((int *)pointer) != 0 ||
	(*((int *)pointer) == 0 && precision > 1 && key == 'o')))
		ft_print_prefix(map);
	if (ft_flag_presence("=", map) == 1)
	{
		precision++;
		ft_putchar('-');
	}
	while (i < precision - len)
	{
		ft_putchar('0');
		i++;
	}
	if (ft_flag_presence("-", map) == 1)
		ft_put_conversion((char *)c, pointer, map);
	if (ft_false_precision((char *)c) == 1)
		return (0);
	return (precision - len);
}

/*
** donne le nombre d'espaces par rapport au flag present
** et a la  taille de la valeure print
*/

int			nbr_of_space(const char *c, void *pointer,
void *charpointer, t_map *map)
{
	int		nbr;
	char	key;

	nbr = 0;
	key = map[ft_end_map(map)].key;
	if (key == 'p')
		nbr = mp_pointer_len(c, charpointer, map) + 2;
	else if (key == 'x' || key == 'X')
		nbr = mp_pointer_len(c, charpointer, map);
	else if (key == 'd' || key == 'i')
		nbr = mp_integer_len(c, pointer, map);
	else if (key == 'u')
		nbr = mp_unsinteger_len(c, pointer, map);
	else if (key == 'o')
		nbr = mp_octal_len(c, pointer, map);
	return (nbr);
}

/*
** imprime les espace et putnbr dans un certain cas
** seulement compatible pour les integer
*/

void		print_space(char *c, int nbr, void *pointer, t_map *map)
{
	char 	key;

	key = map[ft_end_map(map)].key;
	if (ft_flag_presence("-", map) == 1 &&
		ft_flag_presence(".", map) == 0)
		ft_put_conversion(c, pointer, map);
	if (find_precision(c) == 0 && *((int *)pointer) == 0 && ft_strchr("diu", key) != 0)
		nbr++;
	if (nbr < 0)
		nbr = 0;
	while (nbr--)
	{
		if (ft_flag_presence("~", map) == 1 &&
			ft_flag_presence(".", map) == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

int			compute_precision(const char *c, void *cara,
void *charpointer, t_map *map)
{
	int		result;
	char	key;

	key = map[ft_end_map(map)].key;
	if (key == 'p' || key == 'x' || key == 'X')
		result = find_precision(c) - ft_lenpointer(c, charpointer, map);
	if (key == 'd' || key == 'i')
		result = find_precision(c) - ft_nbrlen(*((int *)cara));
	if (key == 'o')
		result = find_precision(c) - ft_octal_len(c, cara, map);
	if (key == 'u')
		result = find_precision(c) - ft_unside_len(c, cara, map);
	if (result < 0)
		result = 0;
	return (result);
}

int			ft_aditional_space(void *cara, t_map *map)
{
	int		nbr;

	nbr = 0;
	if (ft_flag_presence(" ", map) == 1)
		nbr--;
	if (ft_flag_presence("+", map) == 1 && ft_flag_presence("=", map) == 0)
		nbr--;
	if (ft_flag_presence("=", map) == 1 && ft_flag_presence("-", map) == 0 &&
	ft_flag_presence(".", map) == 1)
		nbr--;
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence("=", map) == 1)
		nbr++;
	(void)cara;
	return (nbr);
}

int			ft_bizzare_behavior(const char *c, void *cara, void *charpointer, t_map *map)
{
	if (ft_flag_presence("-", map) == 1)
		return (ft_give_only_len(c, cara, charpointer, map) - find_precision(c));
	else
		return (0);
}

int			ft_putspace(void *cara, void *charpointer,
const char *c, t_map *map)
{
	int i;
	int nbr;
	int	key;

	i = 0;
	key = map[ft_end_map(map)].key;
	while (c[i] && (ft_isdigit(c[i]) == 0 || c[i] == '0'))
		i++;
	if (ft_isdigit(*(c + i)) == 1)
		nbr = ft_atoi(&c[i]) - nbr_of_space(c, cara, charpointer, map);
	else
		nbr = 1;
	nbr += ft_aditional_space(cara, map);
	if (ft_flag_presence(".", map) == 1 && ft_flag_presence("-", map) == 0)
		nbr -= compute_precision(c, cara, charpointer, map);
	if (ft_flag_presence("#", map) == 1 && (*((int *)cara) != 0 ||
	(*((int *)cara) == 0 && find_precision(c) > 1 && key == 'o')))
		nbr -= 2;
	if (find_precision(c) < ft_give_only_len(c, cara, charpointer, map) &&
	ft_flag_presence(".", map) == 1 && ft_prec_0xxo((char *)c, map) == 0)
		nbr -= ft_bizzare_behavior(c, cara, charpointer, map);
	print_space((char *)c, nbr, cara, map);
	return (i);
}
