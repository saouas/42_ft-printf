/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unside_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:58:20 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 20:05:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					mp_unsinteger_len(const char *c, void *pointer, t_map *map)
{
	int				nbr;
	int				len;
	unsigned int	u_nbr;
	char			*str;

	u_nbr = *((int *)pointer);
	str = ft_ulong_itoa((unsigned long)u_nbr);
	len = ft_strlen(str);
	nbr = len;
	if (ft_all_flag_presence(".-", map) == 1)
		nbr += ft_put_precision(c, pointer, map);
	(void)c;
	return (nbr);
}

int					ft_unside_len(const char *c, void *pointer, t_map *map)
{
	int				nbr;
	int				len;
	unsigned int	u_nbr;
	char			*str;

	u_nbr = *((int *)pointer);
	str = ft_ulong_itoa((unsigned long)u_nbr);
	len = ft_strlen(str);
	nbr = len;
	free(str);
	(void)c;
	(void)map;
	return (nbr);
}
