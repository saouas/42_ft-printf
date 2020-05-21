/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salim <salim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:23:08 by ratin             #+#    #+#             */
/*   Updated: 2019/01/31 11:38:10 by salim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	w_ft_size_fields2(void *cara, void *charpointer, const char *c)
{
	int i;

	i = 0;
	i = ft_atoi(c) - ft_strlen(cara);
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

void	w_ft_moins2(void *cara, void *charpointer, const char *c)
{
	int i;

	i = 0;
	if (ft_isthischar((char*)c,'-') == 0)
	{
		return ;
	}
	i = abs_val(ft_atoi(c) + ft_strlen(cara));
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

int	w_ft_putchar(void *cara, void *charpointer, const char *c)
{

	w_ft_size_fields2(cara, charpointer, c);
	ft_putchar(*(char*)charpointer);
	w_ft_moins2(cara, charpointer, c);
	(void)c;
	(void)cara;
	return (ft_pass_flags((char *)c) + 1);
}

int	w_ft_putstr(void *str, void *charpointer, const char *c)
{
	ft_putstr((char *)charpointer);
	(void)c;
	(void)str;
	return (1);
}

int w_ft_binary(void *pointer, void *charpointer, const char *c)
{
	int x;

	x = (*(int*)pointer);
	if (x > 0)
		ft_putstr(C_GREEN"1"C_NONE);
	else if (x <= 0)
		ft_putstr(C_RED"0"C_NONE);
	(void)c;
	(void)charpointer;
	return (1);
}
