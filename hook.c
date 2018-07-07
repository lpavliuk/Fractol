/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:35:30 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/05 12:35:31 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		work_with_color(int keycode, t_frac *frac)
{
	if (keycode == 76)
		COLOR += 1000;
	else if (keycode == 78)
		COLOR -= 1;
	else if (keycode == 69)
		COLOR += 1;
}

static void		work_with_shift(int keycode, t_frac *frac)
{
	double b;

	b = 0.1;
	if (ZOOM > 2 && ZOOM <= 10)
		b = 0.01;
	else if (ZOOM > 10 && ZOOM <= 100)
		b = 0.001;
	else if (ZOOM > 100 && ZOOM <= 1000)
		b = 0.0001;
	else if (ZOOM > 1000)
		b = 0.00001;
	if (keycode == 49)
	{
		MOVE_X = 0;
		MOVE_Y = 0;
		ZOOM = 0.5;
	}
	else if (keycode == 126)
		MOVE_Y -= b;
	else if (keycode == 125)
		MOVE_Y += b;
	else if (keycode == 123)
		MOVE_X -= b;
	else if (keycode == 124)
		MOVE_X += b;
}

int				julia_hook(int x, int y, t_frac *frac)
{
	if (FRACTOL == 2)
	{
		mlx_clear_window(MLX, WIN);
		if (x > 0 && x < WIDTH_W && y > 0 && y < HEIGHT_W)
		{
			CRE = -0.7 * x / 1000;
			CIM = 0.27015 * y / 1000;
		}
		work_pthreads(frac);
	}
	return (0);
}

int				mouse_hook(int keycode, int x, int y, t_frac *frac)
{
	if (keycode == 4 || keycode == 5)
	{
		mlx_clear_window(MLX, WIN);
		if (keycode == 4)
			ZOOM *= 1.1;
		else
			ZOOM *= 0.9;
		work_pthreads(frac);
	}
	return (0);
}

int				key_hook(int keycode, t_frac *frac)
{
	mlx_clear_window(MLX, WIN);
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (keycode == 78 || keycode == 69 || keycode == 76)
		work_with_color(keycode, frac);
	else if (keycode == 123 || keycode == 124 || keycode == 125
		|| keycode == 126 || keycode == 49)
		work_with_shift(keycode, frac);
	work_pthreads(frac);
	return (0);
}
