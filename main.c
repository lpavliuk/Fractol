/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:31:21 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/03 15:31:23 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	exit_x(int keycode)
{
	keycode = 0;
	exit(0);
}

void		ft_error(char *str)
{
	ft_printf(str);
	exit(0);
}

void		create_window(t_frac *frac)
{
	frac->endian = 0;
	frac->bpp = 32;
	frac->size_line = WIDTH_W;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_W, HEIGHT_W, "Fractol");
	IMG_PTR = mlx_new_image(MLX, WIDTH_W, HEIGHT_W);
	IMG = (int *)mlx_get_data_addr(IMG_PTR, &frac->bpp, &frac->size_line, &frac->endian);
}

void		changed_zoom(int keycode, t_frac *frac)
{
	if (keycode == 4)
		frac->zoom += 0.1;
	else
		frac->zoom -= 0.1;
	printf("HEllllllo!\n");
}

int			mouse_hook(int keycode, int x, int y, t_frac *frac)
{
	x = 0;
	y = 0;
	mlx_clear_window(MLX, WIN);	
	if (keycode == 4 || keycode == 5)
		changed_zoom(keycode, frac);
	mandelbrot(frac);
	return (0);
}

void		work_with_color(int keycode, t_frac *frac)
{
	if (keycode == 76)
		COLOR += 1000;
	else if (keycode == 78)
		COLOR += 1;
	else if (keycode == 69)
		COLOR -= 1;
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
	mandelbrot(frac);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_frac *frac;

		frac = (t_frac*)malloc(sizeof(t_frac));
		ZOOM = 1;
		COLOR = 256;
		create_window(frac);
		if (!ft_strcmp(argv[1], "1"))
			mandelbrot(frac);
		else if (!ft_strcmp(argv[1], "2"))
			ft_printf("{green}OK - {yellow}2!\n");
		else if (!ft_strcmp(argv[1], "3"))
			ft_printf("{green}OK - {yellow}3!\n");
		else
			ft_error(ERR_1);
		mlx_hook(WIN, 2, 0, key_hook, frac);
		mlx_mouse_hook(WIN, mouse_hook, frac);
		mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
		mlx_loop(MLX);
	}
	else
		ft_error(ERR_0);
	return (0);
}
