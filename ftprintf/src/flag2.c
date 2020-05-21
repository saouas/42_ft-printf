/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salim <salim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:56:39 by saouas            #+#    #+#             */
/*   Updated: 2019/01/31 11:47:28 by salim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int		w_ft_diese_f(void *pointer, void *charpointer, const char *c)
{
	int		i;
	char	*const_c;

	const_c = (char *)c;
	i = 0;
	if (ft_isthischar(const_c, '#') && ft_isthischar(const_c, '.'))
	{
		while (const_c[i++])
		{
			if ((const_c[i] == '.') && ((const_c[i + 1] == '0') ||
ft_isdigit(const_c[i + 1]) == 0))
			{
				ft_putchar('.');
				return (1);
			}
		}
	}
	(void)pointer;
	(void)charpointer;
	return (0);
}

int		w_ft_moins_f(void *pointer, void *charpointer, const char *c)
{
	int i;

	i = 0;
	if (ft_isthischar((char *)c, '-') == 0)
		return (0);
	//printf("abs(fd) = %d | digit = %d | prec = %d | dernier = %d \n",abs_val(find_field_size(c)), ((is_special((*(long double*)pointer)) == 1) ? is_zeroneg(10): how_much_digit((*(long double *)pointer))), find_precision(c), (((*(int *)pointer) == 0)));
	i = abs_val(find_field_size(c)) + ((ft_isthischar((char*)c, '-') && is_special((*(long double*)pointer)))? 4 : 0) - (ft_isthischar((char *)c, '+') +
ft_isthischar((char *)c, '-') + ((is_special((*(long double*)pointer)) == 1) ? is_zeroneg(10): how_much_digit((*(long double *)pointer)))
 + find_precision(c) + (((*(int *)pointer) == 0) && !is_special((*(long double *)pointer))) + (is_zeroneg((*(long double*)pointer)) && !is_special((*(long double*)pointer)) && ((*(long double*)pointer) == -0.00)));
	//printf("i === %d\n",i);
	if ((ft_isthischar((char*)c, '-') && is_special((*(long double*)pointer)) && is_zeroneg((*(long double*)pointer))))
		i--;
	if (i > 0)
	{
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	else
		return (0);
	(void)charpointer;
	return (1);
}

int		w_ft_plus_f(void *pointer, void *charpointer, const char *c)
{
	long double nbr;

	if (ft_isthischar((char *)c, '+'))
	{
		nbr = ((*(long double *)pointer));
		if (nbr >= 0 && !is_zeroneg((*(long double*)pointer)))
			ft_putchar('+');
	}
	else
		return (0);
	(void)charpointer;
	return (1);
}

int		w_ft_size_fields(void *pointer, void *charpointer, const char *c)
{

	int i;

	i = 0;
	if (find_field_size(c) == -1 || ft_strchr((char *)c, '-') || ft_strchr((char *)c, '0'))
		return(0);
	i = find_field_size(c) - 
	(((is_special((*(long double*)pointer)) == 1) ? is_zeroneg(10): how_much_digit((*(long double *)pointer))) + ft_isthischar((char *)c, '+') +
ft_isthischar((char *)c, '-') + ((is_special((*(long double*)pointer)) == 1) ? is_zeroneg(10) : find_precision(c)) + 2 + is_special((*(long double*)pointer)));
	
	if(is_zeroneg((*(long double*)pointer)))
		i--;
	//printf("i value = %d\n",i);
	if (i > 0)
	{
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	else
		return (0);
	(void)charpointer;
	return (1);
}

int		w_ft_zero_f(void *pointer, void *charpointer, const char *c)
{
	int			i;
	const char	*save_pos;
	int			retour;

	retour = -1;
	save_pos = 0;
	i = 0;
	while (c[i] && c[i] != 'f' && c[i] != ':')
	{
		if (c[i] == '0')
		{
			retour = treat3(c, &i, pointer, save_pos);
			if (retour != 10)
			{
				if (retour == 0)
					return (0);
				if (retour == 1)
					return (1);
			}
		}
		i++;
	}
	(void)charpointer;
	return (1);
}
