/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:12:16 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 17:32:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int len;

	len = ft_strlen(to_find);
	i = 0;
	if (str[0] == '\0' && to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j] && j < len)
			j++;
		if (j == len)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
