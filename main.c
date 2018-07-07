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

static int		exit_x(int keycode)
{
	keycode = 0;
	exit(0);
}

static t_frac	*init_frac(void)
{
	t_frac *frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	ZOOM = 0.5;
	COLOR = 0xF0F0F0;
	MOVE_X = 0;
	MOVE_Y = 0;
	CRE = -0.7;
	CIM = 0.27015;
	FRACTOL = 0;
	MAXITER = 250;
	return (frac);
}

static void		fractol(char *argv)
{
	t_frac	*frac;

	frac = init_frac();
	if (!ft_strcmp(argv, "1"))
		FRACTOL = 1;
	else if (!ft_strcmp(argv, "2"))
		FRACTOL = 2;
	else if (!ft_strcmp(argv, "3"))
		FRACTOL = 3;
	else if (!ft_strcmp(argv, "4"))
		FRACTOL = 4;
	else
	{
		ft_printf(ERR_1);
		exit(0);
	}
	create_window(frac);
	work_pthreads(frac);
	mlx_hook(WIN, 2, 0, key_hook, frac);
	mlx_mouse_hook(WIN, mouse_hook, frac);
	mlx_hook(WIN, 6, 0, julia_hook, frac);
	mlx_hook(WIN, 17, 1L << 17, exit_x, 0);
	mlx_loop(MLX);
}

static void		open_2_window(char **argv)
{
	if (!ft_strcmp(argv[1], "1"))
		system("./fractol 1 &");
	else if (!ft_strcmp(argv[1], "2"))
		system("./fractol 2 &");
	else if (!ft_strcmp(argv[1], "3"))
		system("./fractol 3 &");
	else if (!ft_strcmp(argv[1], "4"))
		system("./fractol 4 &");
	else
	{
		ft_printf(ERR_1);
		exit(0);
	}
	fractol(argv[2]);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		fractol(argv[1]);
	else if (argc == 3)
		open_2_window(argv);
	else
	{
		ft_printf(ERR_0);
		exit(0);
	}
	return (0);
}
