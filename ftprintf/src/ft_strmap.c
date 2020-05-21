/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:05:27 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 17:32:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*ret_str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(ret_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ret_str[i] = f(s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
