/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:09:10 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 23:43:51 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
int is_zeroneg(float f) 
{
    return (*((int*)&f) & 0x80000000) != 0;
}

int			ft_isfloat(char *str, va_list vlst)
{
	int			i;
	long double	nbr2;
	int ret;

	ret = 0;
	i = 0;
	if ((ft_isthischar((char*)str, 'L') == 1 || ft_isthischar((char*)str, 'l') == 1))
		nbr2 = va_arg(vlst, long double);
	else
		nbr2 = va_arg(vlst, double);
	while (str[i] != 'f')
		i++;
	if (is_special((long double)nbr2))
		ret = 0;
	else if (((long int)nbr2 < ((long long int)0) && ft_isthischar((char*)str, '0')) || ((is_zeroneg(nbr2)) && find_field_size(str) == -1))
		ft_putchar('-');
	ret = w_ft_spacebefore_f((void*)&nbr2, (void*)str, str);
	w_ft_size_fields((void*)&nbr2, (void*)str, str);
	if(((is_zeroneg(nbr2) && nbr2 == 0) && is_special((long double)nbr2)) || ((nbr2 == -0.00) && is_zeroneg(nbr2)))
		ft_putchar('-');
	w_ft_plus_f((void*)&nbr2, (void*)str, str);
	w_ft_zero_f((void*)&nbr2, (void*)str, str);
	if (ret != 1)
		w_ft_space_f((void*)&nbr2, (void*)str, str);
	w_ft_special_f((void*)&nbr2, (void*)str, str);
	(is_special(nbr2) == 0) ? w_ft_float((void*)&nbr2, (void*)str, str) : is_zeroneg(10);

	w_ft_diese_f((void*)&nbr2, (void*)str, str);
	w_ft_moins_f((void*)&nbr2, (void*)str, str);
	return (i);
}