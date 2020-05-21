/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zboub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:31:38 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 23:35:27 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{

	int ret;
	int	ret2;

	ret = 0;
	ret2 = 0;
/*
	ret = ft_printf("test basique:");
	printf("\n");
	ret2 = dprintf(2, "test basique:");
	printf("\n");
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("space:% f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "space:% f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("plus:%+f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "plus:%+f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("hash:%#f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "hash:%#f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("precision:%.2f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "precision:%.2f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("big prec:%.14f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "big prec:%.14f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("precision + hash:%#.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "precision + hash:%#.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("space + prec:% .5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "space + prec:% .5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("space + prec + hash:%# .0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "space + prec + hash:%# .0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("space + prec + hash:% #.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "space + prec + hash:% #.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Plus + prec / grande:%+.5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Plus + prec / petite:%+.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Plus + prec + hash:%#+.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Prec + 0:%0.5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Prec + 0:%0.5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Prec + minus:%-.5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Prec + minus:%-.5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size:%5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size:%5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + space:% 5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + space:% 5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + plus:%+5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + plus:%+5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + space:%# 5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + space:%# 5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + plus:%#+5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + plus:%#+5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + minus:%-5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + minus:%-5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + 0:%05f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + 0:%05f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + 0 + plus:%+05f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + 0 + plus:%+05f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + 0 + plus:%0+5f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + 0 + prec:%05.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + 0 + prec:%05.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	*/

/* 
	TEST QUI FAIT TOUT BUG
	ret = ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");


	*/
/*
	ret = ft_printf("Msize + minus + prec:%-5.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Rsize + minus + prec:%-5.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("Msize + minus + prec + hash:%-#5.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "Rsize + minus + prec + hash:%-#5.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");
	
	ret = ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	
	
	ret = ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
	printf("\n");
	ret2 = dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
	printf("ret =%d ret2 = %d", ret, ret2);	
	printf("\n\n");	*/

/*
	double	nb;
	int		ret;
	int		ret2;

	nb = 1.0/0.0;
	ret = ft_printf("%f\n", nb);
	ret2 = dprintf(2,"%f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%12f\n", nb);
	ret2 = dprintf(2,"%12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%-12f\n", nb);
	ret2 = dprintf(2,"%-12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%5.9f\n", nb);
	ret2 = dprintf(2,"%5.9f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	nb = -1.0/0.0;
	ret = ft_printf("%f\n", nb);
	ret2 = dprintf(2,"%f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%12f\n", nb);
	ret2 = dprintf(2,"%12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%-12f\n", nb);
	ret2 = dprintf(2,"%-12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	ret = ft_printf("%5.9f\n", nb);
	ret2 = dprintf(2,"%5.9f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	printf("\n\n--------------------------------------------------------\n\n");
	nb = 0.0/0.0;
	ret = ft_printf("%f\n", nb);
	ret2 = dprintf(2,"%f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	printf("\n\n--------------------------------------------------------\n\n");
	ret = ft_printf("%12f\n", nb);
	ret2 = dprintf(2,"%12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	printf("\n\n--------------------------------------------------------\n\n");
	ret = ft_printf("%-12f\n", nb);
	ret2 = dprintf(2,"%-12f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);

	printf("\n\n--------------------------------------------------------\n\n");
	ret = ft_printf("%5.9f\n", nb);
	ret2 = dprintf(2,"%5.9f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);
*/
	float nb = 0;
	ret = ft_printf("null prec : %+.0f\n", nb);
	ret2= dprintf(2, "null prec : %+.0f\n", nb);
	
	printf("ret = %d et ret2 = %d\n", ret, ret2);
	nb = 12.5;
	ret = ft_printf("null prec : %+.0f\n", nb);
	ret2 = dprintf(2, "null prec : %+.0f\n", nb);
	printf("ret = %d et ret2 = %d\n", ret, ret2);
	nb = -25632.2541;
	ret = ft_printf("null prec : %+.0f\n", nb);
	ret2 = dprintf(2, "null prec : %+.0f\n", nb);

	printf("ret = %d et ret2 = %d\n", ret, ret2);
	
	nb = -1.0123;
	ret = ft_printf("null prec : %+.0f\n", nb);
	ret2 = dprintf(2, "null prec : %+.0f\n", nb);
	
	printf("ret = %d et ret2 = %d\n", ret, ret2);
	nb = 12354.569874;
	ret = ft_printf("null prec : %+.0f\n", nb);
	ret2 = dprintf(2, "null prec : %+.0f\n", nb);

	printf("ret = %d et ret2 = %d\n", ret, ret2);
}