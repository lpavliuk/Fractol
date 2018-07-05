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
	double moveX;
	double moveY;
	int maxIterations;

	maxIterations = 300; 
	moveX = -0.5;
	moveY = 0;
	pr = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + moveX;
	pi = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + moveY;
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
    	IMG[x + (y * WIDTH_W)] = 0x000000;
    else
    	IMG[x + (y * WIDTH_W)] = COLOR * i;
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
