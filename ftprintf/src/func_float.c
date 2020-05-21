/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:27:54 by saouas            #+#    #+#             */
/*   Updated: 2019/01/30 23:40:17 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

long double	ft_round(long double nbr)
{
	return (nbr < 0 ? nbr - 0.5 : nbr + 0.5);
}

int			convert_int_to_str(long long int int_part, char *ret_str,
int precision, long double nbr)
{
	int i;

	i = 0;
	while (int_part && (int_part != 0))
	{
		ret_str[i++] = (int_part % 10) + '0';
		int_part = int_part / 10;
	}
	if (nbr == 0)
		ret_str[i++] = '0';
	while (i < precision)
		ret_str[i++] = '0';
	ft_reverse_str(ret_str, i);
	ret_str[i] = '\0';
	return (i);
}

void		treat2(long double *nbr, long long int *int_part, const char *c)
{
	if (*int_part < ((long long int)0))
	{
		*int_part = *int_part * (long long int)-1;
		if (ft_isthischar((char*)c, '0')==0)
			ft_putchar('-');
		*nbr = *nbr * -1;
	}
}

void		float_itoa(long double nbr, const char *c)
{
	char			*ret_str;
	long long int	int_part;
	long double		double_part;
	int				i;
	int				precision;

	i = 0;
	precision = find_precision(c);
	int_part = (long int)nbr;
	treat2(&nbr, &int_part, c);
	double_part = nbr - (long double)int_part;
	if (!(ret_str = (char *)malloc(sizeof(char) * (i + precision))))
		return ;
	if (precision == 0)
		int_part = ((nbr < 0) ? nbr - 0.49 : nbr + 0.49);
	i = convert_int_to_str(int_part, ret_str, 0, nbr);
	if (precision != 0)
	{
		ret_str[i] = '.';
		i++;
		double_part = double_part * ft_pow(10, precision);
		double_part = ft_round(double_part);
		int_part = (long long int)double_part;
		convert_int_to_str(int_part, ret_str + i, precision, nbr);
	}

	ft_putstr_f(ret_str);
}
