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
	double a;

	a = ZOOM;
	if (keycode == 4)
		ZOOM *= 1.1;
	else
		ZOOM *= 0.9;
	while (a > 1)
		a -= 0.1;
	printf("%f\n", a);
	if (x < WIDTH_W/2)
		MOVE_X -= 0.03;
	else
		MOVE_X += 0.03;
	if (y < HEIGHT_W/2)
		MOVE_Y -= 0.03; 
	else
		MOVE_Y += 0.03;
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
