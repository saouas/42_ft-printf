/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:17:00 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 17:32:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*x;

	x = NULL;
	i = 0;
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			x = (char *)str + i;
			return (x);
		}
		i++;
	}
	return (NULL);
}
