/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 09:25:18 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 14:02:51 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int		ft_found_minus(const char *c, int y)
{
	while (c[y] != '%')
	{
		if (c[y] == '-')
			return (1);
		y--;
	}
	return (0);
}

int		find_precision(const char *c)
{
	const char		*i;
	int				x;
	int				ret;

	ret = 0;
	x = 0;
	i = c;
	while (i[x])
	{
		if (i[x] == '.')
		{
			ret = ft_atoi(&i[x + 1]);
			return (ret);
		}
		x++;
	}
	return (6);
}

int		find_field_size(const char *c)
{
	const char		*i;
	int				x;
	int				ret;

	x = 0;
	ret = 0;
	i = c;
	while (i[x])
	{
		if (i[x++] == '%')	
		{
			while (i[x] == '+' || i[x] == '-' || i[x] == '#')
				x++;
			ret = ft_atoi(i + x);
			return (ret);
		}
		x++;
	}
	return (-1);
}

int		how_much_digit(long double nbr)
{
	long long int		int_part;
	int					i;

	i = 0;
	int_part = (int)nbr;
	while (int_part != 0)
	{
		int_part /= 10;
		i++;
	}
	return (i);
}

void	ft_putstr_f(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && ((ft_isalnum(s[i]) ||
s[i] == '.' || s[i] == '-' || s[i] == '+')))
	{
		ft_putchar(s[i]);
		i++;
	}
}

int		how_many_nbr(char const *c)
{
	int i;
	int count;

	count = 1;
	i = 0;
	while(c[i])
	{
		if (ft_isdigit(c[i]) && c[i - 1] != '.')
			count++;
		i++;
	}
	return (count);
}