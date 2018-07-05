/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:53:53 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/05 12:53:54 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		choose_fractol(t_frac *frac, int x, int y)
{
	if (FRACTOL == 1)
		mandelbrot(frac, x, y);
}

void			draw_fractol(t_frac *frac)
{
	int x;
	int	y;

	x = -1;
	y = -1;
	while (++y < HEIGHT_W)
	{
		x = -1;
		while (++x < WIDTH_W)
			choose_fractol(frac, x, y);
	}
	mlx_put_image_to_window(MLX, WIN, IMG_PTR, 0, 0);
}
