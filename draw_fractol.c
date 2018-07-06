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

static void		*draw_fractol(void *ptk)
{
	int			x;
	int			y;
	int			max_y;
	t_threads	*potok;

	potok = (t_threads *)ptk;
	x = -1;
	y = HEIGHT_W / 8 * potok->num;
	max_y = HEIGHT_W / 8 * (potok->num + 1);
	while (y < max_y)
	{
		x = -1;
		while (++x < WIDTH_W)
			choose_fractol(potok->data, x, y);
		y++;
	}
	return (0);
}

void			work_pthreads(t_frac *frac)
{
	t_threads	potok[8];
	int			i;

	i = -1;
	while (++i < 8)
	{
		potok[i].data = frac;
		potok[i].num = i;
		pthread_create(&potok[i].threads, NULL, draw_fractol, &potok[i]);
	}
	i = -1;
	while (++i < 8)
		pthread_join(potok[i].threads, NULL);
	mlx_put_image_to_window(MLX, WIN, IMG_PTR, 0, 0);
}
