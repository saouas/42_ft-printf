/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:26:08 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 17:32:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			len(unsigned long nb)
{
	unsigned long	nb2;
	int				len_ret;

	nb2 = nb;
	len_ret = 0;
	while (nb2 > 0)
	{
		nb2 = nb2 / 10;
		len_ret++;
	}
	return (len_ret);
}

static	void		count(char *str, unsigned long *nb2, int *i)
{
	while (*nb2 > 0)
	{
		str[*i] = '0' + (*nb2 % 10);
		*nb2 = *nb2 / 10;
		*i -= 1;
	}
}

char				*ft_ulong_itoa(unsigned long nb)
{
	char			*str;
	int				i;
	unsigned long	nb2;

	nb2 = nb;
	if (nb == 0)
		i = 1;
	else
		i = len(nb2);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nb2 == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[i--] = '\0';
	count(str, &nb2, &i);
	return (str);
}
