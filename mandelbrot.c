/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:24:08 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/04 17:24:09 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	algorithm(t_frac *frac, int x, int y)
{
	int i;
	double pr;
	double pi;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	double zoom; 
	double moveX;
	double moveY;
	int maxIterations;
	unsigned int color;

	maxIterations = 300;
	zoom = 1; 
	moveX = -0.5;
	moveY = 0;
	pr = 1.5 * (x - WIDTH_W / 2) / (0.5 * zoom * WIDTH_W) + moveX;
	pi = (y - HEIGHT_W / 2) / (0.5 * zoom * HEIGHT_W) + moveY;
	newRe = newIm = oldRe = oldIm = 0;
	i = -1;
	while(++i < maxIterations)
	{
		oldRe = newRe;
		oldIm = newIm;

		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		newIm = 2 * oldRe * oldIm + pi;
		if((newRe * newRe + newIm * newIm) > 4)
    		break;
  	}
    if (i == maxIterations)
    {
    	// color = mlx_get_color_vlue(MLX, 0x000000);
    	// ft_printf("{red} ");
    	// IMG[(x * 4) + (y * WIDTH_W)];
    	IMG[x + (y * WIDTH_W)] = 0x000000;
    		// ft_memset(IMG + ((x) + (y * WIDTH_W)), 0xFFFFFF, sizeof(unsigned int));
    }
    else
    {
    	// ft_printf("{red} %u", color);
    	// color = mlx_get_color_value(MLX, 256 + i);
    	IMG[x + (y * WIDTH_W)] = 256 * i;
    	// ft_memset(IMG + ((x) + (y * WIDTH_W)), 0xFF0000, sizeof(unsigned int));
    }
}

void		mandelbrot(t_frac *frac)
{
	int x;
	int	y;

	x = -1;
	y = -1;
	while (++y < HEIGHT_W)
	{
		x = -1;
		while (++x < WIDTH_W)
			algorithm(frac, x, y);
	}
	mlx_put_image_to_window(MLX, WIN, IMG_PTR, 0, 0);
}
