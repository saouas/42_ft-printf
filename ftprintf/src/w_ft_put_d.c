/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_put_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 00:04:52 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** cherche le premier digit si le caractere d'avant est un point renvoi 0
** renvoie 1 a l'inverse et -1 si c ne contient aucun digit
*/

int			ft_is_not_point(char *c)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, c[i]))
	{
		if (ft_isdigit(c[i]) && c[i - 1] != '.')
			return (1);
		else if (ft_isdigit(c[i]) && c[i - 1] == '.')
			return (0);
		i++;
	}
	return (-1);
}

static int	give_error(t_map *map)
{
	if (ft_flag_presence("#", map) == 1)
		return (-1);
	if (ft_all_flag_presence("~-", map) == 1 ||
		ft_all_flag_presence(" +", map) == 1)
		return (-1);
	return (0);
}

static	int	put_flag(char *c, void *nb, void *charpointer, t_map *map)
{
	int		minus;

	minus = 0;
	if (ft_flag_presence(" ", map) == 1 && ft_flag_presence("=", map) == 0)
		ft_putchar(' ');
	if (ft_flag_presence("123456789", map) == 1)
	{
		if ((ft_flag_presence("-~", map) == 0 && ft_is_not_point(c) == 1))
			ft_putspace(nb, nb, c, map);
		else if (ft_flag_presence("-", map) == 1)
			minus = 1;
	}
	if (ft_flag_presence("~", map) == 1)
	{
		if (ft_flag_presence("+", map) == 1 && ft_flag_presence("=", map) == 0 &&
		ft_flag_presence(".", map) == 0)
			ft_putchar('+');
		if (ft_flag_presence("=", map) == 1 &&
		ft_flag_presence(".", map) == 0)
			ft_putchar('-');
		if (ft_is_not_point(c) == 1)
			ft_putspace(nb, nb, c, map);
		if (ft_flag_presence("+", map) == 1 && ft_flag_presence("=", map) == 0 &&
		ft_flag_presence(".", map) == 1)
			ft_putchar('+');
	}
	if (ft_flag_presence("+", map) == 1 &&
	ft_flag_presence("~", map) == 0 && *((int *)nb) >= 0)
		ft_putchar('+');
	if (ft_flag_presence(".", map) == 1 &&
	ft_flag_presence("-", map) == 0)
		ft_put_precision(c, nb, map);
	if (minus == 0)
		ft_put_conversion(c, nb, map);
	if (minus == 1)
		ft_putspace(nb, nb, c, map);
	(void)charpointer;
	return (0);
}

int			w_ft_putnbr(void *nb, void *charpointer, const char *c)
{
	t_map	*map;

	map = ft_create_map(c, nb);
	if (give_error(map) == -1)
		return (-1);
	put_flag((char *)c, nb, charpointer, map);
	free(map);
	return (ft_pass_flags((char *)c) + 1);
}
