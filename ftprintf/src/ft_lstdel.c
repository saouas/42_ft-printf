/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:06:43 by saouas            #+#    #+#             */
/*   Updated: 2019/01/23 20:27:23 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *current;

	current = *alst;
	while (current)
	{
		next = current->next;
		del(current->content, current->content_size);
		current = next;
	}
	*alst = NULL;
}
