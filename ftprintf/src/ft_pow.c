/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:08:56 by salim             #+#    #+#             */
/*   Updated: 2019/01/15 19:15:31 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_pow(int x, unsigned int y)
{
	long long int tmp;

	tmp = 1;
	if (y == 0)
		return (tmp);
	else
		while (y != 0)
		{
			tmp = x * tmp;
			y--;
		}
	return (tmp);
}
