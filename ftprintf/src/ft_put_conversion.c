/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:23:55 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 17:52:02 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					put_octal(void *pointer, t_map *map)
{
	char			*str;
	char			*result;
	unsigned int	u_nbr;

	if (*((int *)pointer) == 0)
		result = ft_strdup("0");
	else
	{
		u_nbr = *((int *)pointer);
		str = ft_ulong_itoa((unsigned long)u_nbr);
		result = ft_convert_base_finale(str, "01234567");
	}
	if (ft_flag_presence("#", map) == 1 && ft_flag_presence("~", map) == 0 &&
	ft_flag_presence(".", map) == 0 && *((int *)pointer) != 0)
		ft_putchar('0');
	ft_putstr(result);
	return (1);
}

int					mp_octal_len(const char *c, void *pointer, t_map *map)
{
	char			*str;
	char			*result;
	int				nbr;
	unsigned int	u_nbr;

	if (*((int *)pointer) == 0)
	{
		if (ft_flag_presence(".", map) == 1 && find_precision(c) == 0)
		{
			if (ft_flag_presence("#", map) == 1)
				nbr = 2;
			else
				nbr = 0;
		}
		else
			nbr = 1;
	}
	else
	{
		u_nbr = *((int *)pointer);
		str = ft_ulong_itoa((unsigned long)u_nbr);
		result = ft_convert_base_finale(str, "01234567");
		nbr = ft_strlen(result);
	}
	if (ft_flag_presence("#", map) == 1)
		nbr--;
	if (ft_all_flag_presence(".-", map) == 1)
		nbr += ft_put_precision(c, pointer, map);
	return (nbr);
}

int					ft_octal_len(const char *c, void *pointer, t_map *map)
{
	char			*str;
	char			*result;
	int				nbr;
	unsigned int	u_nbr;

	if (*((int *)pointer) == 0)
		nbr = 1;
	else
	{
		u_nbr = *((int *)pointer);
		str = ft_ulong_itoa((unsigned long)u_nbr);
		result = ft_convert_base_finale(str, "01234567");
		nbr = ft_strlen(result);
	}
	if (ft_flag_presence("#", map) == 1)
		nbr++;
	(void)c;
	return (nbr);
}

void	ft_put_decimal(char *c, void *pointer, t_map *map)
{
	if (ft_flag_presence("~", map) == 0 && ft_flag_presence(".", map) == 0)
		ft_putnbr(*((int *)pointer));
	else if ((ft_flag_presence("~", map) == 1 ||
	ft_flag_presence(".", map) == 1) && ft_flag_presence("=", map) == 1)
	{
		*((int *)pointer) = *((int *)pointer) * -1;
		ft_putnbr(*((int *)pointer));
	}
	else if (ft_flag_presence("=", map) == 0)
		ft_putnbr(*((int *)pointer));
	(void)c;
}

void	ft_put_conversion(char *c, void *pointer, t_map *map)
{
	int	key;

	key = map[ft_end_map(map)].key;
	if (find_precision(c) == 0 && *((int *)pointer) == 0)
	{
		if (ft_flag_presence("#", map) == 1 && key == 'o')
			ft_print_prefix(map);
		return ;
	}
	if (key == 'd' || key == 'i')
		ft_put_decimal(c, pointer, map);
	else if (key == 'u')
		ft_putunbr(*((unsigned int *)pointer));
	else if (key == 'x' || key == 'X')
		ft_print_pointer(pointer, map);
	else if (key == 'o')
		put_octal(pointer, map);
}
