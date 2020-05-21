/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <saouas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 21:48:46 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 23:28:54 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int		is_special(long double nbr)
{
	double POS_INF = 1.0 /0.0;
	double NEG_INF = -1.0/0.0;

	if (nbr != nbr)
		return (1);
	else if (nbr == POS_INF)
		return (1);
	else if (nbr == NEG_INF)
		return (1);
	else
		return (0);
}

int		w_ft_special_f(void *pointer, void *charpointer, const char *c)
{
	double POS_INF = 1.0 /0.0;
	double NEG_INF = -1.0/0.0;

	(void)charpointer;
	(void)c;
	if ((*(long double*)pointer) != (*(long double*)pointer))
	{
		ft_putstr("nan");
		return (1);
	}
	
	else if ((*(long double*)pointer) == POS_INF)
	{
		ft_putstr("inf");
		return (1);
	}
	
	else if ((*(long double*)pointer) == NEG_INF)
	{	
		ft_putstr("-inf");
		return (1);
	}
	else
		return (0);
}

int		w_ft_space_f(void *pointer, void *charpointer, const char *c)
{
	int i;
	int x;

	x = 0;
	i = 0;
	(void)pointer;
	(void)charpointer;
	if ((*(long double*)pointer) < 0 || is_zeroneg((*(long double*)pointer)))
		return (0);

	if (ft_isthischar((char*)c, 32))
	{
		while(c[x++] && c[i + 1] != 32)
			if(c[x] == '%' || c[x] == '#')
				i++;
		//printf("nbr ret = %d",how_many_nbr((char*)c));
		if (how_many_nbr((char *)c) > 1)
			i++;
		//printf("\n\n|||| %c ||||\n\n",c[i]);
		if(ft_isthischar((char *)c, '#') && c[i + 1] != 32 && c[i] != 32)
			i++;
		//printf("||%c|| \n",c[i]);
		
		if (c[i + 1] == 32 || c[i] == 32)
		{
			//puts("lalallalalaalalalla\n\n");
			ft_putchar(32);
		}
		return(1);
	}
	return (0);
}


int			w_ft_spacebefore_f(void *pointer, void* charpointer, const char *c)
{
	int i;
	int x;

	x = 0;
	i = 0;
	(void)pointer;
	(void)charpointer;

	if ((*(long double*)pointer) < 0 || is_zeroneg((*(long double*)pointer)))
		return (0);
	if (ft_isthischar((char*)c, 32))
	{
		while(c[x++] && c[i + 1] != 32)
			if(c[x] == '%' || c[x] == '#')
				i++;
		//printf("nbr ret = %d",how_many_nbr((char*)c));
		if (how_many_nbr((char *)c) > 1)
			i++;
		//printf("\n\n|||| %c ||||\n\n",c[i]);
		if(ft_isthischar((char *)c, '#') && c[i + 1] != 32 && c[i] != 32)
			i++;
		//printf("||%c|| \n",c[i]);
		
		if (c[i + 1] == 32 || c[i] == 32)
		{
			//puts("lalallalalaalalalla\n\n");
			ft_putchar(32);
		}
		return(1);
	}
	return (0);
}
int	treat3(const char *c, int *i, void *pointer, const char *save_pos)
{
	//printf("c = %s \n",c);
	while (c[*i] == '+' || c[*i] == '-' || c[*i] == '#' || c[*i] == ' ' )
		(*i)++;
	if (ft_isdigit(c[*i]))
	{
		save_pos = c + *i + 1;
		(*i)++;
		if(ft_isthischar((char *)c + *i, '#'))
			{
				while(c[(*i)++])
				{
					if (ft_isdigit(c[*i]))
					{
						save_pos = c + *i;
						break;
					}
				}
			}
		while (c[(*i)++] != 'f')
		{
			if (ft_isthischar((char *)c, '-'))
				return (0);
		}
		*i = ft_atoi(save_pos) + ((is_zeroneg((*(long double*)pointer)) && (ft_isthischar((char *)c, '#')))) - find_precision(c) -
((*(long double*)pointer == -0.0) && (is_zeroneg((*(long double*)pointer))) ? is_zeroneg(-0.0) : how_much_digit((*(long double *)pointer))) -
(((*(long double*)pointer) <= ((long double)0)) ? 1 : 0) - ft_isthischar((char *)c, '+') - ft_isthischar((char *)c, 32);
		if (*i > 0)
			while (*i > 0)
			{
				(*i)--;
				if (*i != 0)
					ft_putchar('0');
				else
					return (1);
			}
		else
			return(0);
	}
	return (10);
}
