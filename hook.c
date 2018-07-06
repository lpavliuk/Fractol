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

static void		changed_zoom(int keycode, t_frac *frac, int x, int y)
{
	if (keycode == 4)
		ZOOM *= 1.1;
	else if (keycode == 5)
		ZOOM *= 0.9;
}

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

	if (ZOOM < 2)
		b = 0.1;
	else if (ZOOM < 10)
		b = 0.01;
	else if (ZOOM < 100)
		b = 0.001;
	else if (ZOOM < 1000)
		b = 0.0001;
	else
		b = 0.00001;
	if (keycode == 49)
	{
		MOVE_X = -0.5;
		MOVE_Y = 0;
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

int				mouse_hook(int keycode, int x, int y, t_frac *frac)
{
	mlx_clear_window(MLX, WIN);
	if (keycode == 4 || keycode == 5 || keycode == 1 || keycode == 2)
		changed_zoom(keycode, frac, x, y);
	work_pthreads(frac);
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
