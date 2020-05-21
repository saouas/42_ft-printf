/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tabinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:39:58 by ratin             #+#    #+#             */
/*   Updated: 2019/01/29 18:51:45 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_init_tab(void)
{
	g_p[0] = w_ft_putchar;
	g_p[1] = w_ft_put_long;
	g_p[2] = w_ft_putpointer;
	g_p[3] = w_ft_putnbr;
	g_p[4] = w_ft_putnbr;
	g_p[5] = w_ft_putconverted;
	g_p[6] = w_ft_putconverted;
	g_p[7] = w_ft_putconverted;
	g_p[8] = w_ft_putconverted;
	g_p[9] = w_ft_put_long;
	g_p[10] = w_ft_put_long;
	g_p[11] = w_ft_put_z;
	g_p[12] = w_ft_binary;
	g_p[13] = w_ft_str_color;
}
