/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_putconverted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:59:56 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	give_error(t_map *map)
{
	char	key;

	key = map[ft_end_map(map)].key;
	if (ft_flag_presence(" +#", map) == 1 && key == 'u')
		return (-1);
	if (ft_all_flag_presence("~-", map) == 1)
		return (-1);
	return (0);
}

void		ft_print_prefix(t_map *map)
{
	char	key;

	key = map[ft_end_map(map)].key;
	if (key == 'x' || key == 'p')
		ft_putstr("0x");
	else if (key == 'X')
		ft_putstr("0X");
	else if (key == 'o')
		ft_putstr("0");
}

static	int	put_flag(char *c, void *nb, t_map *map)
{
	int		minus;

	minus = 0;
	if (ft_flag_presence(" ", map) == 1)
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
		if (ft_flag_presence("#", map) == 1 && ft_flag_presence(".", map) == 0)
			ft_print_prefix(map);
		if (ft_is_not_point(c) == 1)
			ft_putspace(nb, nb, c, map);
	}
	if (ft_flag_presence(".", map) == 1 &&
	ft_flag_presence("-", map) == 0)
		ft_put_precision(c, nb, map);
	if (minus == 0)
		ft_put_conversion(c, nb, map);
	if (minus == 1)
		ft_putspace(nb, nb, c, map);
	return (0);
}

int			w_ft_putconverted(void *nb, void *charpointer, const char *c)
{
	t_map	*map;

	map = ft_create_map(c, nb);
	if (give_error(map) == -1)
		return (-1);
	put_flag((char *)c, nb, map);
	free(map);
	(void)charpointer;
	return (ft_pass_flags((char *)c) + 1);
}
