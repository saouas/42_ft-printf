/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:03:10 by ratin             #+#    #+#             */
/*   Updated: 2019/01/23 17:32:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_words_tables(char **tab)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (tab[i])
	{
		while (tab[i][y] != '\0')
		{
			ft_putchar(tab[i][y]);
			y++;
		}
		y = 0;
		i++;
		ft_putchar('\n');
	}
}
