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
	int endian;
	int bpp;
	int size_line;

	endian = 0;
	bpp = 32;
	size_line = WIDTH_W;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH_W, HEIGHT_W, "Fractol");
	IMG_PTR = mlx_new_image(MLX, WIDTH_W, HEIGHT_W);
	IMG = mlx_get_data_addr(IMG_PTR, &bpp, &size_line, &endian);
}





int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_frac *frac;

		frac = malloc(sizeof(t_frac));
		if (!ft_strcmp(argv[1], "1"))
			mandelbrot(frac);
		else if (!ft_strcmp(argv[1], "2"))
			ft_printf("{green}OK - {yellow}2!\n");
		else if (!ft_strcmp(argv[1], "3"))
			ft_printf("{green}OK - {yellow}3!\n");
		else
			ft_error(ERR_1);
		create_window(frac);
		// mlx_hook(WIN, 2, 0, key_hook, fdf);
		mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
		mlx_loop(MLX);
	}
	else
		ft_error(ERR_0);
	return (0);
}
