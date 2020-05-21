/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:14:51 by ratin             #+#    #+#             */
/*   Updated: 2019/01/30 18:58:39 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

/*
** recois une string a partir du 1er caratere apre le '%'
** et renvois 1 si le caractere de conversion est valide (cspdiouxX)
** si il s'agit d'un mauvais caractere la fonction renvoi 0
*/

int		ft_pass_flags(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(FLAGS, str[i]))
		i++;
	if (ft_strchr("cspdiouxXfzbm", str[i]))
		return (i);
	return (0);
}

/*
** recois une string a partir du 1er caratere apre le '%'
** et renvois le caractere de conversion (cspdiouxX)
** si il s'agit d'un mauvais caractere la fonction renvoi 0
*/

char	ft_find_param(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(" ~-+0123456789#.=", str[i]))
		i++;
	if (ft_strchr("cspdiouxXfzbmlh", str[i]))
		return (str[i]);
	return (0);
}

char	ft_float_param(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(" ~-+0123456789#.=lL", str[i]))
		i++;
	if (ft_strchr("cspdiouxXfzbm", str[i]))
		return (str[i]);
	return (0);
}

char	ft_find_key(char *str)
{
	int i;

	i = 0;
	while (ft_strchr(FLAGS, str[i]))
		i++;
	if (ft_strchr("cspdiouxXf", str[i]))
		return (str[i]);
	return (0);
}

/*
** recois un chaine de caractere
** trouve le caractere de conversion
** retourne 1 si il sagit du caracter demande (flag)
*/

int		ft_find_flag(char *str, char flag)
{
	int i;

	i = 0;
	while (ft_strchr("cspdiouxXf", str[i]) == 0)
	{
		if (str[i] == flag)
			return (1);
		if (flag == '~' && str[i] == '0' && ft_isdigit(str[i - 1]) == 0 &&
		str[i - 1] != '.')
			return (1);
		if (flag == '&' && str[i] == '0' && ft_isdigit(str[i - 1]) == 0 &&
		str[i - 1] != '.' && ft_zero_discovery(&str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}


/*
** confirme la presence d'un digit apres un zero seul
*/

int		ft_zero_discovery(char *str)
{
	int	i;

	i = 1;
	while (str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 1)
		return (1);
	return (0);
}
