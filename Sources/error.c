/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:22:35 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/12 15:26:32 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_usage(void)
{
	ft_putstr("usage: fractol [mandelbrot | julia]\n");
	exit(EXIT_FAILURE);
}
