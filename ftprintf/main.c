/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:10:29 by ratin             #+#    #+#             */
/*   Updated: 2019/01/23 21:27:43 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void	ft_printmap(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].present != -1)
	{
		printf("Pour %c map indique %d\n", map[i].key, map[i].present);
		i++;
	}
	printf("Pour %c map indique %d\n", map[i].key, map[i].present);
}

int		main(void)
{
	int	nbr = 4253;
	unsigned int unbr = -429;
	int	result;
	char str[] = "vfjsadfklji la string de test";
	int res = 0;
	const char *test;

	unsigned char snb = '0';
	unsigned int art = 3423;
	double dodo = 4324.4;

/* TEST DE CONVERT BASE */
	//printf("conversion = %s\n", ft_convert_base_finale("432", "0123456789", "0123456789abcdef"));

	printf("\n------test de la conversion 'p'-------\n\n");
	result = ft_printf("mon printf = |%-10p|\n", str);
				printf("rea printf = |%-10p|\n", str);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 'd'-------\n\n");
	result = ft_printf("mon printf = |%-24d|\n", nbr);
				printf("rea printf = |%-24d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");
 
	result = ft_printf("mon printf = |% 025d|\n", nbr);
				printf("rea printf = |% 025d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |% d|\n", nbr);
				printf("rea printf = |% d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test du flag '+'-------\n\n");
	result = ft_printf("mon printf = |%+24d|\n", nbr);
				printf("rea printf = |%+24d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%+024d|\n", nbr);
				printf("rea printf = |%+024d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la precision (d,i)-------\n\n");
	result = ft_printf("mon printf = |%-24.20d|\n", nbr);
				printf("rea printf = |%-24.20d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%24.13d|\n", nbr);
				printf("rea printf = |%24.13d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-24.13d|\n", nbr);
				printf("rea printf = |%-24.13d|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-.33i|\n", nbr);
				printf("mon printf = |%-.33i|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 'u'-------\n\n");
	result = ft_printf("mon printf = |%024.14u|\n", unbr);
				printf("rea printf = |%024.14u|\n", unbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%024.3u|\n", unbr);
				printf("rea printf = |%024.3u|\n", unbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%.43u|\n", unbr);
				printf("rea printf = |%.43u|\n", unbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%32u|\n", unbr);
				printf("rea printf = |%32u|\n", unbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");


	printf("\n------test de la conversion 'x'-------\n\n");
	result = ft_printf("mon printf = |%-24x|\n", nbr);
				printf("rea printf = |%-24x|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-#32x|\n", nbr);
				printf("rea printf = |%-#32x|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-#32X|\n", nbr);
				printf("rea printf = |%-#32X|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%0#32X|\n", nbr);
				printf("rea printf = |%0#32X|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32.8X|\n", nbr);
				printf("rea printf = |%-32.8X|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%12.11X|\n", nbr);
				printf("rea printf = |%12.11X|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%30.2x|\n", nbr);
				printf("rea printf = |%30.2x|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%30.20x|\n", nbr);
				printf("rea printf = |%30.20x|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 'o'-------\n\n");

	result = ft_printf("mon printf = |%-24o|\n", nbr);
				printf("rea printf = |%-24o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-#32o|\n", nbr);
				printf("rea printf = |%-#32o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

 	result = ft_printf("mon printf = |%-#32o|\n", nbr);
				printf("rea printf = |%-#32o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%0#32o|\n", nbr);
				printf("rea printf = |%0#32o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32.8o|\n", nbr);
				printf("rea printf = |%-32.8o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%32.8o|\n", nbr);
				printf("rea printf = |%32.8o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%12.11o|\n", nbr);
				printf("rea printf = |%12.11o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%#30.24o|\n", nbr);
				printf("lrea printf = |%#30.24o|\n", nbr);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 'l'-------\n\n");

	unsigned long long int	sht = 18446744073709551615ULL; // valeure max gere

	result = ft_printf("mon printf = |%-24lld|\n", sht);
				printf("rea printf = |%-24lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32lld|\n", sht);
				printf("rea printf = |%-32lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-2lld|\n", sht);
				printf("rea printf = |%-2lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%032lld|\n", sht);
				printf("rea printf = |%032lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32.23lld|\n", sht);
				printf("rea printf = |%-32.23lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%32.2lld|\n", sht);
				printf("rea printf = |%32.2lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");


	result = ft_printf("mon printf = |%12.11lld|\n", sht);
				printf("rea printf = |%12.11lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%-30.24lld|\n", sht);
				printf("lrea printf = |%-30.24lld|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");


	printf("888888888888888888888888888888888888888888\n");
	result = ft_printf("lmon printf = |%30.24llu|\n", sht);
				printf("lrea printf = |%30.24llu|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");
	result = ft_printf("lmon printf = |%30.24llx|\n", sht);
				printf("lrea printf = |%30.24llx|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%30.24llo|\n", sht);
				printf("lrea printf = |%30.24llo|\n", sht);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 'h'-------\n\n");

	short		max = 32534;

	result = ft_printf("mon printf = |%-24hd|\n", max);
				printf("rea printf = |%-24hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32hd|\n", max);
				printf("rea printf = |%-32hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-2hd|\n", max);
				printf("rea printf = |%-2hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%032hd|\n", max);
				printf("rea printf = |%032hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%-32.23hd|\n", max);
				printf("rea printf = |%-32.23hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("mon printf = |%32.2hd|\n", max);
				printf("rea printf = |%32.2hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");


	result = ft_printf("mon printf = |%12.11hd|\n", max);
				printf("rea printf = |%12.11hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%-30.24hd|\n", max);
				printf("lrea printf = |%-30.24hd|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");


	printf("888888888888888888888888888888888888888888\n");
	result = ft_printf("lmon printf = |%30.24hu|\n", max);
				printf("lrea printf = |%30.24hu|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%30.24hx|\n", max);
				printf("lrea printf = |%30.24hx|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	result = ft_printf("lmon printf = |%30.24ho|\n", max);
				printf("lrea printf = |%30.24ho|\n", max);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n------test de la conversion 's'-------\n\n");

	char *string = "test conversion de s";
	result = ft_printf("lmon printf = |%-34s|\n", string);
				printf("lrea printf = |%-34s|\n", string);
	printf("ma fonction printf renvoie : %d\n", result);
	printf("\n");

	printf("\n");

/* 	printf("conversion = %s\n", ft_convert_base_finale("4294967295","0123456789abcdef"));
	unsigned int negato = -1;
	printf("negato = %u\n", negato); */

	//printf("%s\n", ft_convert_base_finale("140734585289440", "0123456789abcdef"));
/* TEST DE LA CREATION DE LA MAP DE FLAG */
/* 	void *pointer = NULL;
	void *charpointer = NULL;
	t_map *map = ft_create_map("0+26.1p");
	ft_printmap(map); */

/*PARAMS FOR FLOAT TEST*/	
/*	long double nbr2 = 192326.6;
	test = "%0+26.1f"; */
//	#include <float.h>
	/* Respect priority order for treatment : F -> + -> 0 -> float calcul */
/*	w_ft_size_fields((void*)&nbr2, (void*)test, test);
	w_ft_plus_f((void*)&nbr2, (void*)test, test);
	w_ft_zero_f((void*)&nbr2, (void*)test, test);
	w_ft_float((void*)&nbr2, (void*)test, test);*/

//	printf("\nR:%Lf\n",DBL_MAX);*/

 printf("\n------test de la conversion 'f et L'-------\n\n");

	printf("Rea printf : %.11Lf\n",192326.62L); 
	ft_printf("Mon printf : %.11Lf\n", 192326.62);
	ft_putchar('\n');
	printf("Rea printf : %.11lf\n",192326.62); 
	ft_printf("Mon printf : %.11lf\n",192326.62L);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	//probleme de precision
	printf("Rea printf :%043.18f\n",1234567891.313432);
	ft_printf("Mon printf :%043.18f\n",1234567891.313432);
	ft_putchar('\n');
	printf("Rea printf :%077.18f\n",1239994561.313511432);
	ft_printf("Mon printf :%077.18f\n",1239994561.313511432);
	ft_putchar('\n');
	printf("Rea printf char :: %cR:%#0.f int %d\n",'a',125.3,10);
	ft_printf("Mon printf char :: %cM:%#0.f int %d\n",'a',125.3,10);
	ft_putchar('\n'); 
	printf("Rea printf :%44.18f\n",-1234567891.313432);
	ft_printf("Mon printf :%44.18f\n",-1234567891.313432);
	ft_putchar('\n'); 
	printf("Rea printf :%044.18f\n",-1234567891.313432);
	ft_printf("Mon printf :%044.18f\n",-1234567891.313432);
	
	ft_putchar('\n');
	ft_putchar('\n');

	printf("\n------test de la conversion 'lld'-------\n\n");
	
	printf("Rea printf :%ld\n",9223372036854775807);
	ft_printf("Mon printf :%ld\n",9223372036854775807);
	ft_ul_convert_base_finale("10","123456789ABCDEF");


	printf("\n------test de la convesion bunus'z with fields'-------\n\n");
	printf("%zu\n",(size_t)192);		
	ft_printf("%z\n",(size_t)192);		

	ft_putchar('\n');

	printf("%17zu\n",(size_t)192);		
	ft_printf("%17z\n",(size_t)192);		
	printf("\n------test de la conversion 'c with fields and flag -'-------\n\n");

	printf("Rea printf :%-10cvoila\n",4+48);
	ft_printf("Mon printf :%-10cvoila\n",4+48);

	ft_putchar('\n');

	printf("Rea printf :%cvoila\n",4+48);
	ft_printf("Mon printf :%cvoila\n",4+48);
	ft_putchar('\n');
	ft_putchar('\n');


	printf("\n------test de la conversion 'b : en bonus'-------\n\n");

	ft_printf("%b\n",10);
	ft_printf("%b\n",0);
	ft_printf("%b\n",-10);

	ft_putchar('\n');
	ft_putchar('\n');

	printf("\n------test de la conversion 'm : en bonus'-------\n\n");
	char x[] = "Hello Wolrd";
	ft_printf("%mG\n",x);

	ft_putchar('\n');
	ft_putchar('\n');
	printf("Rea printf :%5%\n");
	ft_printf("Mon printf :%5%\n");

//test
/*
	printf("\n------test de CONVERT BASE -------\n\n");
	char *ret = ft_convert_base_finale("2147483648", "0123456789ABCDEF");
	printf("Rea: %s",ret);

	ft_printf("COOOOOOOOOOOOOOOOOO: %s\n",ft_convert_base_finale("140734781381136", "0123456789ABCDEF"));
*/
	/* TEST POUR FLAGS hh h l ll -*/
/* 
	printf("\n------test du flag 'hh'-------\n\n");
	printf("Without hh :%d\n",123456);
	printf("With hh    :%d\n",123456);


	ft_printf("Mon: %s\n",ft_convert_base_finale("123456","01234567"));
 *//*	char a;

	a = 3;
	ft_printf("Salut %p\n",a);
	return (0);*/

	//ft_putnbr(4294967295);

/* 
unsigned long long la;
la = 18446744073709551505ull;
int fr = -43;
ft_putchar('\n');
ft_printf("nbr = %042d\n", fr);
printf("nbr = %042d\n", fr); */

//	char *ret;

//	 long long nbr32 = 9223372036854775806;
//	ret = ft_litoa(nbr32);
//	ft_printf("%s",ret);
}
