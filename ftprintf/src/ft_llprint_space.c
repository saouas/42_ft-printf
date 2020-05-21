/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llprint_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:12:07 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:46:36 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						ft_put_llprecision(char *nombre, const char *c,
t_map *map)
{
	int					precision;
	int					len;
	int					i;
	char				key;

	i = 0;
	key = map[ft_end_map(map)].key;
	if (ft_flag_presence("#", map) == 1)
		ft_print_prefix(map);
	len = ft_strlen(nombre);
	precision = find_precision(c);
	if (nombre[0] == '-')
	{
		precision++;
		ft_putchar('-');
	}
	while (i < precision - len && ft_strchr("dixXou", key) != 0)
	{
		ft_putchar('0');
		i++;
	}
	if (ft_flag_presence("-", map) == 1)
		ft_put_llconv(nombre, map);
	return (precision - len);
}

int						precision_len(char *nombre, const char *c, t_map *map)
{
	int					result;
	int					small;
	char				key;

	key = map[ft_end_map(map)].key;
	result = find_precision(c) - ft_strlen(nombre);
	small = 0;
	if (result < 0)
	{
		if (find_precision(c) < (int)ft_strlen(nombre))
			return (0);
		small = 1;
		result = result * -1;
	}
	if (ft_flag_presence(".", map) == 1 && ft_strchr("dixXou", key) != 0)
	{
		if (nombre[0] == '-' && small == 0)
			return ((result + 1) * -1);
		else
			return (result * -1);
	}
	return (0);
}

void					ft_llprint_space(int nbr, char *nombre, t_map *map)
{
	if (ft_flag_presence("-", map) == 1 &&
		ft_flag_presence(".", map) == 0)
		ft_put_llconv(nombre, map);
	if (ft_flag_presence("~", map) == 1 && nombre[0] == '-' &&
	ft_flag_presence("&", map) == 0 && ft_flag_presence(".", map) == 0)
		ft_putchar('-');
	if (ft_flag_presence("+", map) == 1 && ft_flag_presence("=", map) == 0)
		nbr--;
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence("=", map) == 0)
		nbr--;
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

int						ft_llputspace(char *nombre, const char *c, t_map *map)
{
	int					i;
	int					nbr;
	char				key;

	i = 0;
	key = map[ft_end_map(map)].key;
	while (c[i] && (ft_isdigit(c[i]) == 0 || c[i] == '0'))
		i++;
	if (ft_isdigit(*(c + i)) == 1 && c[i - 1] != '.')
		nbr = ft_atoi(&c[i]) - ft_strlen(nombre);
	else
		nbr = 0;
	nbr += precision_len(nombre, c, map);
	if (ft_all_flag_presence(".-", map) == 1)
		ft_put_llprecision(nombre, c, map);
	if (ft_flag_presence("#", map) == 1)
	{
		if (key == 'o')
			nbr--;
		else if (key == 'x' || key == 'X')
			nbr -= 2;
	}
	ft_llprint_space(nbr, nombre, map);
	return (0);
}
