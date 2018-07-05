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
	if (-0.5 < -0.5 + (float)x * 0.0009)
		MS_X = -0.1;
	else
		MS_X = 0.1;
	if (0 < 0 + (float)y * 0.0009)
		MS_Y = -0.1;
	else
		MS_Y = 0.1;
	if (keycode == 4)
		ZOOM += 0.1;
	else
		ZOOM -= 0.1;
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

int			mouse_hook(int keycode, int x, int y, t_frac *frac)
{
	mlx_clear_window(MLX, WIN);	
	if (keycode == 4 || keycode == 5)
		changed_zoom(keycode, frac, x, y);
	work_pthreads(frac);
	return (0);
}

int			key_hook(int keycode, t_frac *frac)
{
	mlx_clear_window(MLX, WIN);
	if (keycode == 53)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (keycode == 78 || keycode == 69 || keycode == 76)
		work_with_color(keycode, frac);
	work_pthreads(frac);
	return (0);
}
