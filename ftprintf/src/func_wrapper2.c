/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_wrapper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 04:08:49 by ratin             #+#    #+#             */
/*   Updated: 2019/01/24 00:30:26 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_field_size1(const char *c)
{
	const char		*i;
	int				x;
	int				ret;

	x = 0;
	ret = 0;
	i = c;
	if (ft_isdigit(c[0]))
	{
		while (i[x] == '+' || i[x] == '-')
			x++;
		ret = ft_atoi(i + x + 1);
		return (ret);
	}
	return (-1);
}
size_t	how_much_digit_sizet(size_t nbr)
{
	size_t		int_part;
	size_t		i;

	i = 0;
	int_part = (size_t)nbr;
	while (int_part != 0)
	{
		int_part /= 10;
		i++;
	}
	return (i);
}
void	w_ft_size_fields3(void *pointer, void *charpointer, const char *c)
{
	size_t i;

	i = 0;
	if (find_field_size1(c) == -1)
		return ;
	i = ft_atoi(c) - how_much_digit_sizet(*((size_t* )pointer));
	if (i > 0)
	{
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	(void)charpointer;
}

int		w_ft_float(void *nbr, void *charpointer, const char *c)
{
	float_itoa(*(long double *)nbr, c);
	(void)c;
	return (1);
	(void)charpointer;
}

int w_ft_put_z(void *pointer ,void *charpointer, const char *c)
{
	w_ft_size_fields3(pointer, charpointer, c);
	ft_putunbr(*((size_t *)pointer));
	(void)c;
	(void)charpointer;
	return (ft_pass_flags((char *)c) + 1);
}
