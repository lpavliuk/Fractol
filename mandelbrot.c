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

void		mandelbrot(t_frac *frac, int x, int y)
{
	int i;
	double pr;
	double pi;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	int maxIterations;

	maxIterations = 100; 
	MOVE_X = -0.5 + MS_X;
	MOVE_Y = 0 + MS_Y;
	pr = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	pi = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
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
