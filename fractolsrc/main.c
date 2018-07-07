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
	CHANGED = 1;
	ZOOM = 0.5;
	COLOR = 0x0F0F0F;
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
	choose_fractol(argv, frac);
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
	if (!ft_strcmp(argv[1], "mandelbrot"))
		system("./fractol mandelbrot &");
	else if (!ft_strcmp(argv[1], "julia"))
		system("./fractol julia &");
	else if (!ft_strcmp(argv[1], "tricorn"))
		system("./fractol tricorn &");
	else if (!ft_strcmp(argv[1], "celtic"))
		system("./fractol celtic &");
	else if (!ft_strcmp(argv[1], "corridor"))
		system("./fractol corridor &");
	else if (!ft_strcmp(argv[1], "carpet"))
		system("./fractol carpet &");
	else if (!ft_strcmp(argv[1], "flower"))
		system("./fractol flower &");
	else if (!ft_strcmp(argv[1], "burning_ship"))
		system("./fractol burning_ship &");
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
		ft_printf("{green}Usage: {blue}./fractol ");
		ft_printf("{yellow}[name of fractol 1] {blue}&& ");
		ft_printf("{yellow}[name of fractol 2] ☝️ 😏 \n");
		ft_printf("✅ | mandelbrot\n");
		ft_printf("✅ | julia\n");
		ft_printf("✅ | tricorn\n");
		ft_printf("✅ | celtic\n");
		ft_printf("✅ | corridor\n");
		ft_printf("✅ | carpet\n");
		ft_printf("✅ | flower\n");
		ft_printf("✅ | burning_ship\n");
		exit(0);
	}
	return (0);
}
