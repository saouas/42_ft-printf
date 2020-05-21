/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:48:12 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** calcule la taille de la string imprimer
*/

int	mp_pointer_len(const char *c, void *charpointer, t_map *map)
{
	char	*str;
	char	*result;
	char	key;
	int		nbr;
	unsigned int u_nbr;

	u_nbr = *((int *)charpointer);
	key = map[ft_end_map(map)].key;
	if (key == 'p')
		str = ft_ulong_itoa((unsigned long)charpointer);
	if (key == 'x' || key == 'X')
		str = ft_ulong_itoa((unsigned long)u_nbr);
	result = ft_convert_base_finale(str, "0123456789abcdef");
	nbr = ft_strlen(result);
	if (ft_all_flag_presence(".-", map) == 1 && key != 'p')
		nbr += ft_put_precision(c, charpointer, map);
	free(result);
	return (nbr);
}

int	ft_lenpointer(const char *c, void *charpointer, t_map *map)
{
	char *str;
	char *result;
	char	key;
	unsigned int u_nbr;

	key = map[ft_end_map(map)].key;
	u_nbr = *((int *)charpointer);
	if (key == 'x' || key == 'X')
		str = ft_ulong_itoa((unsigned long)u_nbr);
	else
		str = ft_itoa(*(int *)charpointer);
	result = ft_convert_base_finale(str, "0123456789abcdef");
	(void)c;
	free(result);
	return (ft_strlen(result));
}

int	mp_integer_len(const char *c, void *pointer, t_map *map)
{
	int nbr;
	int len;

	len = ft_nbrlen(*((int *)pointer));
	nbr = len;
	if (ft_all_flag_presence(".-", map) == 1)
		nbr += ft_put_precision(c, pointer, map);
	return (nbr);
}

/*
** donne la len de l'element convertit
*/

int	ft_size_conversion(const char *c, void *pointer,
void *charpointer, t_map *map)
{
	char key;

	key = map[ft_end_map(map)].key;
	if (key == 'd')
		return (mp_integer_len(c, pointer, map));
	if (key == 'u')
		return (ft_nbrlen(*((int *)pointer)));
	if (key == 'p')
		return (mp_pointer_len(c, charpointer, map));
	if (key == 'x' || key == 'x')
		return (mp_pointer_len(c, pointer, map));
	if (key == 'o')
		return (ft_octal_len(c, pointer, map));
	return (0);
}

int	ft_give_only_len(const char *c, void *pointer,
void *charpointer, t_map *map)
{
	char key;

	key = map[ft_end_map(map)].key;
	if (key == 'd')
		return (ft_nbrlen(*((int *)pointer)));
	if (key == 'u')
		return (ft_nbrlen(*((int *)pointer)));
	if (key == 'x' || key == 'X')
		return (ft_lenpointer(c, pointer, map));
	if (key == 'o')
		return (ft_octal_len(c, pointer, map));
	(void)charpointer;
	return (0);
}
