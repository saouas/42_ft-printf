/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salim <salim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:12:02 by ratin             #+#    #+#             */
/*   Updated: 2019/01/31 11:37:04 by salim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"
#include <stdarg.h>

/*
** cherche une correspondance a c dans le tableau de fonction
** verifier le retour de l'appel de fonction
*/

int			ft_call_func(const char *c, void *pointer, int cursor)
{
	int		i;
	int		error;

	i = 0;
	while (g_ptab[i])
	{
		if (ft_find_param((char *)c) == g_ptab[i])
		{
			error = cursor;
			cursor += (*g_p[i])((void *)&pointer, (void *)pointer, c);
			if (cursor < error)
				return (-1);
		}
		i++;
	}
	return (cursor);
}

void		*treat4(long long int nbr)
{
	char	*ret;
	void	*pointer;

	if ((unsigned long long)nbr == -9223372036854775808ull)
	{
		ret = (char *)malloc(sizeof(char) * 21);
		ft_strcpy(ret, "-9223372036854775808");
	}
	else
		ret = ft_litoa(nbr);
	pointer = ret;
	return (pointer);
}

/*
** va_arg est lancer a partir d'ici
*/

int				ft_compute_arg(const char *str, int i, va_list vlst)
{
	void		*pointer;
	t_map		*map;
	long long	nbr;

	pointer = NULL;
	map = ft_create_map(&str[i], pointer);
	if (ft_verif_arg(str[++i]) == 0)
		return (-1);
	if (ft_verif_arg(str[i]) == 1)
	{
		if (ft_float_param((char *)&str[i]) == 'f')
		{
			return (i + ft_isfloat((char *)&str[i - 1], vlst));
		}
		else if (ft_flag_presence("l", map) == 1)
		{
			nbr = va_arg(vlst, long long int);
			pointer = treat4(nbr);
		}
		else if (ft_flag_presence("h", map) == 1)
		{
			nbr = va_arg(vlst, int);
			pointer = treat4(nbr);
		}
		else
			pointer = va_arg(vlst, void *);
		if ((i = ft_call_func(&str[i], pointer, i)) == -1)
			return (-1);
	}
	free(map);
	return (i);
}

/*
** print la string avant le '%'
** appel la fonction qui cherche le caracter dans le tableau de fonction
** return (-1) si jammais le caractere n'est pas present dans le tab
*/

int			ft_print_string(const char *str, va_list vlst)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			if ((i = ft_compute_arg(str, i, vlst)) == -1)
				return (-1);
			if (!(str[i]))
				return (0);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			i++;
		ft_putchar(str[i]);
		i++;
	}
	va_end(vlst);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list vlst;

	g_terminal = 0;
	g_ptab = ft_strdup("cspdiouxXlhzbm #0f+.-123456789L");
	ft_init_tab();
	va_start(vlst, format);
	if (ft_print_string(format, vlst) == -1)
		return (-1);
	free(g_ptab);
	return (g_terminal);
}

void	ft_printmap(t_map *map)
{
	int	i;

	i = 0;
	printf("\n");
	while (map[i].present != -1)
	{
		printf("Pour %c map indique %d\n", map[i].key, map[i].present);
		i++;
	}
	printf("Pour %c map indique %d\n", map[i].key, map[i].present);
}
