/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ft_putpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:16:39 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:05:12 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_print_pointer(void *pointer, t_map *map)
{
	char	*str;
	char	*result;
	char	key;
	unsigned int nbr;

	key = map[ft_end_map(map)].key;
	nbr = *((int *)pointer);
	if (key == 'X' || key == 'x')
	{
		str = ft_ulong_itoa((unsigned long)nbr);
		if (key == 'X')
			result = ft_convert_base_finale(str, "0123456789ABCDEF");
		else
			result = ft_convert_base_finale(str, "0123456789abcdef");
	}
	else
	{
		str = ft_ulong_itoa((unsigned long )pointer);
		result = ft_convert_base_finale(str, "0123456789abcdef");
	}
	if (key == 'p' || (ft_flag_presence("#", map) == 1 &&
	ft_flag_presence("~", map) == 0 && ft_flag_presence(".", map) == 0))
		ft_print_prefix(map);
	ft_putstr(result);
	free(result);
	free(str);
}

int			w_ft_putpointer(void *nb, void *charpointer, const char *c)
{
	t_map	*map;
	int		minus;

	minus = 0;
	map = ft_create_map(c, nb);
	if (ft_flag_presence(" ~+#.", map) == 1)
		return (-1);
	if (ft_flag_presence("123456789", map) == 1)
	{
		if (ft_flag_presence("-", map) == 0)
			ft_putspace(nb, charpointer, c, map);
		else
			minus = 1;
	}
	ft_print_pointer(charpointer, map);
	if (minus == 1)
		ft_putspace(nb, charpointer, c, map);
	free(map);
	return (ft_pass_flags((char *)c) + 1);
}
