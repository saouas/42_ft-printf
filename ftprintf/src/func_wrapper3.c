/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_wrapper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:13:48 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 14:57:34 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Usage : ft_printf("%mL","Hello World"); L is the color
** color L = b:bold B:black R:red G:green M:magenta C:cyan G:grey
*/
char	*wich_color(const char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[1] == 'b')
			return(C_BOLD);
		if (c[1] == 'B')
			return(C_BLACK);
		if (c[1] == 'R')
			return(C_RED);
		if (c[1] == 'G')
			return (C_GREEN);
		if (c[1] == 'C')
			return (C_CYAN);
		if (c[1] == 'G')
			return (C_GRAY);
		i++;
	}
	return("error");
}

int		w_ft_str_color(void *str, void *charpointer, const char *c)
{
	char *color;
	color = wich_color(c);
	if (color[1] != 'e')
	{
		ft_putstr(color);
		ft_putstr((char *)charpointer);
		ft_putstr(C_NONE);
	}
	(void)c;
	(void)str;
	return (2);
}