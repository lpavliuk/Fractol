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

void		mandelbrot(t_frac *frac, int x, int y, t_value *value)
{
	int i;
	int	maxiterations;

	maxiterations = 250;
	value->pr = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	value->pi = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
	value->newRe = 0;
	value->newIm = 0;
	value->oldRe = 0;
	value->oldIm = 0;
	i = -1;
	while(++i < maxiterations)
	{
		value->oldRe = value->newRe;
		value->oldIm = value->newIm;

		value->newRe = value->oldRe * value->oldRe
		- value->oldIm * value->oldIm + value->pr;
		value->newIm = 2 * value->oldRe * value->oldIm + value->pi;
		if((value->newRe * value->newRe + value->newIm * value->newIm) > 4)
    		break;
  	}
    if (i == maxiterations)
    	IMG[x + (y * WIDTH_W)] = 0x000000;
    else
    	IMG[x + (y * WIDTH_W)] = COLOR * i;
}
