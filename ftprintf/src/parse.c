/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:05:12 by ratin             #+#    #+#             */
/*   Updated: 2019/01/16 20:55:55 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

/*
** verifie sur l'argument est present dans le tab
*/

int		ft_verif_arg(char c)
{
	int		i;

	i = 0;
	while (g_ptab[i])
	{
		if (c == g_ptab[i])
			return (1);
		i++;
	}
	return (0);
}
