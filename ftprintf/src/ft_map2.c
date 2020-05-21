/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:40:20 by saouas            #+#    #+#             */
/*   Updated: 2019/01/21 23:33:03 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	verifie la presence de tous les flags de str
*/

int		ft_all_flag_presence(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (map_checker(str[i], map) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_map	*ft_nbr_is_negatif(void *nbr, t_map *map)
{
	int	i;
	char key;

	i = 0;
	key = map[ft_end_map(map)].key;
	if (nbr == NULL)
		return (map);
	if (ft_strchr("xXou", key) == 0)
	{
		while (map[i].key != '=')
			i++;
		if (ft_flag_presence("lh", map) == 1)
		{
			if (((char *)nbr)[0] == '-' && key == 'd')
				map[i].present = 1;
		}
		else if (*((int *)nbr) < 0)
			map[i].present = 1;
	}
	return (map);
}
