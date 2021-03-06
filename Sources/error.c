/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:22:35 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/07 10:26:26 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_usage(void)
{
	ft_putstr("usage: ./fractol [-mpz] brain | burningship | julia | ");
	ft_putstr("mandelbrot | newton | sierpinski\n");
	exit(EXIT_FAILURE);
}

void	error_opt(char opt)
{
	ft_putstr("./fractol: illegal option -- ");
	ft_putchar(opt);
	ft_putchar('\n');
	error_usage();
}
