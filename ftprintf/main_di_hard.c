/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_di_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:50:09 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 22:05:12 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "limits.h"

int		main()
{
	short           nb;
	int				ret;
	int				ret2;

	ret = ft_printf("Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
	printf("\n");
	ret2= dprintf(2, "Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
	printf("\nret = %d et ret2 = %d\n", ret, ret2);	

/* 	nb = -23;
	ret = ft_printf("max int :  %d", INT16_MAX);
	printf("\n");	
	ret2 = dprintf(2, "max int :  %d", INT16_MAX);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("min int :  %d", INT16_MIN);
	printf("\n");	
	ret2 = dprintf(2, "min int :  %d", INT16_MIN);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("max int :  %d", INT32_MAX);
	printf("\n");	
	ret2 = dprintf(2, "max int :  %d", INT32_MAX);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("min int :  %d", INT32_MIN);
	printf("\n");	
	ret2 = dprintf(2, "min int :  %d", INT32_MIN);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("max long :  %ld", LONG_MAX);
	printf("\n");	
	ret2 = dprintf(2, "max long :  %ld", LONG_MAX);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("min long :  %ld", LONG_MIN);
	printf("\n");	
	ret2 = dprintf(2, "min long :  %ld", LONG_MIN);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("max long long :  %lld", __LONG_LONG_MAX__);
	printf("\n");	
	ret2 = dprintf(2, "max long long :  %lld", __LONG_LONG_MAX__);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n");

	ret = ft_printf("min long long :  %lld",LLONG_MIN);
	printf("\n");	
	ret2 = dprintf(2, "min long long :  %lld",LLONG_MIN);
	printf("\nret = %d et ret2 = %d", ret, ret2);	
	printf("\n\n"); */


}