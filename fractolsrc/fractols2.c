/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:47:07 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/07 15:47:08 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		corridor(t_frac *frac, int x, int y)
{
	int		i;
	t_value	value;

	value.newre = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	value.newim = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
	i = -1;
	while (++i < MAXITER)
	{
		value.oldre = value.newre;
		value.oldim = value.newim;
		value.newre = log(value.oldre * value.oldre)
		- log(value.oldim * value.oldim) + CRE;
		value.newim = 2 * cos(value.oldre * value.oldim) + CIM;
		if ((value.newre * value.newre + value.newim * value.newim) > 4)
			break ;
	}
	if (i == MAXITER)
		IMG[x + (y * WIDTH_W)] = 0x000000;
	else
		IMG[x + (y * WIDTH_W)] = COLOR * i;
}

void		carpet(t_frac *frac, int x, int y)
{
	int		i;
	t_value	value;

	value.newre = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	value.newim = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
	i = -1;
	while (++i < MAXITER)
	{
		value.oldre = value.newre;
		value.oldim = value.newim;
		value.newre = tan(value.oldre * value.oldre)
		- atan(value.oldim * value.oldim) + CRE;
		value.newim = 2 * sin(value.oldre * value.oldim) + CIM;
		if ((value.newre * value.newre + value.newim * value.newim) > 4)
			break ;
	}
	if (i == MAXITER)
		IMG[x + (y * WIDTH_W)] = 0x000000;
	else
		IMG[x + (y * WIDTH_W)] = COLOR * i;
}

void		flower(t_frac *frac, int x, int y)
{
	int		i;
	t_value	value;

	value.newre = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	value.newim = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
	i = -1;
	while (++i < MAXITER)
	{
		value.oldre = value.newre;
		value.oldim = value.newim;
		value.newre = log(value.oldre * value.oldre)
		- log(value.oldim * value.oldim) + CRE;
		value.newim = 2 * -(value.oldre * value.oldim) + CIM;
		if ((value.newre * value.newre + value.newim * value.newim) > 4)
			break ;
	}
	if (i == MAXITER)
		IMG[x + (y * WIDTH_W)] = 0x000000;
	else
		IMG[x + (y * WIDTH_W)] = COLOR * i;
}

void		burning_ship(t_frac *frac, int x, int y)
{
	int		i;
	t_value	value;

	value.pr = 1.5 * (x - WIDTH_W / 2) / (0.5 * ZOOM * WIDTH_W) + MOVE_X;
	value.pi = (y - HEIGHT_W / 2) / (0.5 * ZOOM * HEIGHT_W) + MOVE_Y;
	value.newre = 0;
	value.newim = 0;
	i = -1;
	while (++i < MAXITER)
	{
		value.oldre = value.newre;
		value.oldim = value.newim;
		value.newre = value.oldre * value.oldre
		- value.oldim * value.oldim + value.pr;
		value.newim = 2 * fabs(value.oldre * value.oldim) + value.pi;
		if ((value.newre * value.newre + value.newim * value.newim) > 4)
			break ;
	}
	if (i == MAXITER)
		IMG[x + (y * WIDTH_W)] = 0x000000;
	else
		IMG[x + (y * WIDTH_W)] = COLOR * i;
}
