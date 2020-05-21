/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_put_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:21:09 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:37:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

int						ft_llflag_erro(t_map *map)
{
	char				key;

	key = map[ft_end_map(map)].key;
	if (key == 'd' || key == 'i')
	{
		if (ft_flag_presence("#", map) == 1)
			return (-1);
		if (ft_all_flag_presence("~-", map) == 1 ||
			ft_all_flag_presence(" +", map) == 1)
			return (-1);
	}
	else if (key == 's')
	{
		if (ft_flag_presence("lh=# +#", map) == 1 && key == 'u')
			return (-1);	
	}
	else
	{
		if (ft_flag_presence(" +#", map) == 1 && key == 'u')
			return (-1);
		if (ft_all_flag_presence("~-", map) == 1)
			return (-1);
	}
	return (0);
}

void					ft_put_llconv(char *nombre, t_map *map)
{
	if ((ft_flag_presence("~", map) == 1 || ft_flag_presence(".", map) == 1) &&
	ft_flag_presence("=", map) == 1)
		ft_putstr(&nombre[1]);
	else
		ft_putstr(nombre);
}

int						minos(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

void					ft_put_flagbis(int minus, char *nombre,
const char *c, t_map *map)
{
	char				key;

	key = map[ft_end_map(map)].key;
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence(".", map) == 1 &&
	find_precision(c) < ((int)ft_strlen(nombre)))
		ft_putchar(' ');
	if (ft_flag_presence(".", map) == 1 &&
	ft_flag_presence("-", map) == 0 && ft_strchr("dixXou", key) != 0)
		ft_put_llprecision(nombre, c, map);
	if (minus == 0)
	{
		if (ft_flag_presence("#", map) == 1 && ft_flag_presence("~", map) == 0 &&
		ft_flag_presence(".", map) == 0 && ft_strcmp("0", nombre) != 0)
			ft_print_prefix(map);
		ft_put_llconv(nombre, map);
	}
	if (minus == 1)
		ft_llputspace(nombre, c, map);
}

int						ft_put_flag(char *nombre, const char *c, t_map *map)
{
	int					minus;

	minus = 0;
	if (ft_llflag_erro(map) == -1)
		return (-1);
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence(".", map) == 0 && ft_flag_presence("=", map) == 0)
		ft_putchar(' ');
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence(".", map) == 1 &&
	find_precision(c) >= (int)ft_strlen(nombre) &&
	ft_flag_presence("=", map) == 0)
		ft_putchar(' ');
	if (ft_flag_presence("123456789", map) == 1)
	{
		if ((ft_flag_presence("-~", map) == 0 && ft_is_not_point((char *)c) == 1))
			ft_llputspace(nombre, c, map);
		else if (ft_flag_presence("-", map) == 1)
			minus = 1;
	}
	if (ft_flag_presence("~", map) == 1)
	{
		if (ft_flag_presence("+", map) == 1 && nombre[0] != '-' &&
		ft_flag_presence(".", map) == 0)
			ft_putchar('+');
		if (ft_flag_presence("#", map) == 1 && ft_flag_presence(".", map) == 0)
			ft_print_prefix(map);
		if (ft_is_not_point((char *)c) == 1)
			ft_llputspace(nombre, c, map);
		if (ft_flag_presence("+", map) == 1 && nombre[0] != '-' &&
		ft_flag_presence(".", map) == 1)
			ft_putchar('+');
	}
	if (ft_flag_presence("+", map) == 1 &&
	ft_flag_presence("~", map) == 0 && nombre[0] != '-')
		ft_putchar('+');
	ft_put_flagbis(minus, nombre, c, map);
	return (0);
}

int						ft_space_only(const char *c, t_map *map)
{
	int					i;
	int					nbr;

	i = 0;
	while (c[i] && (ft_isdigit(c[i]) == 0 || c[i] == '0'))
	{
		if (c[i] == '.')
			return (0);
		i++;
	}
	if (ft_isdigit(*(c + i)) == 1)
		nbr = ft_atoi(&c[i]);
	else
		nbr = 1;
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
	return (0);
}

int						ft_empty_string(t_map *map, const char *c)
{
	if (ft_llflag_erro(map) == -1)
		return (-1);
	if (ft_flag_presence("123456789", map) == 1)
		ft_space_only(c, map);
	return (ft_pass_flags((char *)c) + 1);
}

int						ft_space_null(char *nombre, const char *c, t_map *map)
{
	int					i;
	int					nbr;

	i = 0;
	while (c[i] && (ft_isdigit(c[i]) == 0 || c[i] == '0'))
	{
		if (c[i] == '.')
			return (0);
		i++;
	}
	if (ft_isdigit(*(c + i)) == 1)
		nbr = ft_atoi(&c[i]) - ft_strlen(nombre);
	else
		nbr = 1;
	if (ft_flag_presence(".", map) == 1 && find_precision(c) < (int)ft_strlen(nombre))
		nbr += (ft_strlen(nombre) - find_precision(c));
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
	return (0);
}

int						ft_null_string(char *nombre, const char *c, t_map *map)
{
	if (ft_llflag_erro(map) == -1)
		return (-1);
	if (ft_flag_presence("123456789", map) == 1 && ft_flag_presence("-", map) == 0)
		ft_space_null(nombre, c, map);
	ft_putstr(ft_put_precisionstr(nombre, c, map));
	if (ft_flag_presence("123456789", map) == 1 && ft_flag_presence("-", map) == 1)
		ft_space_null(nombre, c, map);
	return (ft_pass_flags((char *)c) + 1);
}

int						w_ft_put_long(void *nb, void *charpointer, const char *c)
{
	char				*nombre;
	t_map				*map;

	map = ft_create_map(c, charpointer);
	nombre = ft_give_conversion((char *)charpointer, map, c);
	//printf("charpointer = %s")
/* 	if ((char *)charpointer != NULL && ft_strcmp((char *)charpointer, "") == 0 && ft_strcmp("(null)", nombre) != 0)
		return (ft_empty_string(map, c)); */
	if ((char *)charpointer == NULL)
		return (ft_null_string(nombre, c, map));
	if ((ft_put_flag(nombre, c, map)) == -1)
		return (-1);
	(void)nb;
	return (ft_pass_flags((char *)c) + 1);
}
