/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_o_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:31:36 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 16:22:21 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
	int	ret;
	int	ret2;

	int	nb = 0;
	/* ret = ft_printf("test o:%o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "test o:%o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("hash:%#o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "hash:%#o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("precision / grande:%.5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "precision / grande:%.5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("Prec + hash / grande:%#.5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "Prec + hash / grande:%#.5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("Prec + hash / petite:%#.1o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "Prec + hash / petite:%#.1o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

 */	

	ret = ft_printf("Prec + 0:%0.5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "Prec + 0:%0.5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("Prec + minus:%-.5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "Prec + minus:%-.5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("Size:%5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "Size:%5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + prec:%7.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + prec:%7.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + minus:%-5o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + minus:%-5o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + zero:%05o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + zero:%05o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + zero + hash:%#05o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + zero + hash:%#05o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + zero + prec:%05.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + zero + prec:%05.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + minus + prec:%-5.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + minus + prec:%-5.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + hash + zero + prec:%#05.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + hash + zero + prec:%0#5.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);
	printf("\n");	
	ret2 = dprintf(2, "size + hash + minus + prec:%-#7.3o\n", nb);
	printf("ret = %d et ret 2 = %d\n", ret, ret2);	
	printf("\n\n");

	return (0);
}