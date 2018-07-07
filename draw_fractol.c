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

static void		draw(t_frac *frac, int x, int y)
{
	if (FRACTOL == 1)
		mandelbrot(frac, x, y);
	else if (FRACTOL == 2)
		julia(frac, x, y);
	else if (FRACTOL == 3)
		tricorn(frac, x, y);
	else if (FRACTOL == 4)
		celtic_mandelbrot(frac, x, y);
	else if (FRACTOL == 5)
		corridor(frac, x, y);
	else if (FRACTOL == 6)
		carpet(frac, x, y);
	else if (FRACTOL == 7)
		flower(frac, x, y);
	else if (FRACTOL == 8)
		burning_ship(frac, x, y);
}

static void		*draw_fractol(void *ptk)
{
	int			x;
	int			y;
	int			max_y;
	t_threads	*potok;

	potok = (t_threads *)ptk;
	x = -1;
	y = HEIGHT_W / 4 * potok->num;
	max_y = HEIGHT_W / 4 * (potok->num + 1);
	while (y < max_y)
	{
		x = -1;
		while (++x < WIDTH_W)
			draw(potok->data, x, y);
		y++;
	}
	return (0);
}

void			work_pthreads(t_frac *frac)
{
	t_threads	potok[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		potok[i].data = frac;
		potok[i].num = i;
		pthread_create(&potok[i].threads, NULL, draw_fractol, &potok[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(potok[i].threads, NULL);
	mlx_put_image_to_window(MLX, WIN, IMG_PTR, 0, 0);
}

void			create_window(t_frac *frac)
{
	frac->endian = 0;
	frac->bpp = 32;
	frac->size_line = WIDTH_W;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_W, HEIGHT_W, "Fractol");
	IMG_PTR = mlx_new_image(MLX, WIDTH_W, HEIGHT_W);
	IMG = (int *)mlx_get_data_addr(IMG_PTR, &frac->bpp,
		&frac->size_line, &frac->endian);
}
