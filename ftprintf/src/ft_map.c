/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:09:50 by ratin             #+#    #+#             */
/*   Updated: 2019/01/21 23:35:18 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** renvoie l'index du dernier element du tableau
*/

int		ft_end_map(t_map *map)
{
	int		i;

	i = 0;
	while (map[i].present != -1)
		i++;
	return (i);
}

/*
** cree un tableau de type map eyant pour taille le nombre de flags present dans
** le define FLAGS
** assigne le caractere de conversion a l'element
** .key de la derniere case du tableau
** assigne -1 l'element .present de la derniere case du tableau
*/

t_map	*flag_map(char *str)
{
	t_map	*map;
	int		i;

	i = 0;
	if ((map = malloc(sizeof(t_map) * (ft_strlen(FLAGS) + 1))) == NULL)
		return (0);
	while (FLAGS[i])
	{
		map[i].key = FLAGS[i];
		map[i].present = 0;
		i++;
	}
	map[i].key = ft_find_key(str);
	map[i].present = -1;
	return (map);
}

/*
** assigne 1 a .present lorsque le flag corespondant est present dans *c
*/

t_map	*ft_create_map(const char *c, void *pointer)
{
	t_map	*map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if ((map = flag_map((char *)c)) == 0)
		return (0);
	while (FLAGS[i])
	{
		if (ft_find_flag((char *)c, FLAGS[i]) == 1)
		{
			while (map[k].key != FLAGS[i])
				k++;
			map[k].present = 1;
		}
		i++;
	}
	map = ft_nbr_is_negatif(pointer, map);
	return (map);
}

/*
** verifie la valeur de l'element .present pour flag
*/

int		map_checker(char flag, t_map *map)
{
	int	i;

	i = 0;
	while (map[i].present != -1)
	{
		if (map[i].key == flag)
			return (map[i].present);
		i++;
	}
	return (0);
}

/*
**	verifie la presence d'au moin un des flags de str
*/

int		ft_flag_presence(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (map_checker(str[i], map) == 1)
			return (1);
		i++;
	}
	return (0);
}
