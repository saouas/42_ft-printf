/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:45:40 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 19:05:09 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*ft_put_precisionstr(char *str, const char *c, t_map *map)
{
	size_t			precision;

	if (ft_flag_presence(".", map) == 1)
	{
		precision = find_precision(c);
		if (precision < ft_strlen(str))
			return (ft_strsub(str, 0, precision));
	}
	return (str);
}

char				*ft_give_conversion(char *str, t_map *map, const char *c)
{
	char			key;
	long long int	u_nbr;
	char			*u_str;

	if (str == NULL)
		return ("(null)");
	u_nbr = ft_ullatoi(str);
	u_str = ft_ulong_itoa((unsigned long)u_nbr);
	key = map[ft_end_map(map)].key;
	if (key == 'u')
		return (u_str);
	if (key == 'x')
		return (ft_ul_convert_base_finale(u_str, "0123456789abcdef"));
	if (key == 'X')
		return (ft_ul_convert_base_finale(u_str, "0123456789ABCDEF"));
	if (key == 'o')
		return (ft_ul_convert_base_finale(u_str, "01234567"));
	if (key == 's')
		return (ft_put_precisionstr(str, c, map));
	return (str);
}

int					ft_false_precision(char *c)
{
	int				i;

	i = 0;
	while (c[i] && ft_strchr("cspdiouxXf", c[i]) == 0)
	{
		if (c[i] == '.' && ft_isdigit(c[i + 1]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*
** retourne 1 si la precision = 0 et key = x,X ou o
*/

int					ft_prec_0xxo(char *c, t_map *map)
{
	char			key;

	key = map[ft_end_map(map)].key;
	if (ft_strchr("xXo", key) != 0 && find_precision(c) == 0)
		return (1);
	return (0);
}
