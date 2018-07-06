/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:31:15 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/03 15:31:17 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define ERR_0 "{green}Usage: {blue}./fractol {yellow}[name of fractol] ☝️ 😏\n"
# define ERR_1 "{red}Error: {yellow}There isn't this type of fractol! 🤔\n"

# define MLX frac->mlx_ptr
# define WIN frac->win_ptr
# define IMG_PTR frac->img_ptr
# define IMG frac->img
# define ZOOM frac->zoom
# define COLOR frac->color
# define MOVE_X frac->move_x
# define MOVE_Y frac->move_y
# define MS_X frac->mouse_x
# define MS_Y frac->mouse_y
# define FRACTOL frac->number
# define PR frac->pr
# define PI frac->pi
# define NEWRE frac->newRe
# define NEWIM frac->newIm
# define OLDRE frac->oldRe
# define OLDIM frac->oldIm

# define WIDTH_W 1200
# define HEIGHT_W 700

typedef struct	s_frac
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img;
	int		color;
	int		bpp;
	int		size_line;
	int		endian;
	int		number;
	double	move_x;
	double	move_y;
	double	zoom;
}				t_frac;

typedef struct	s_value
{
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
}				t_value;

typedef struct	s_threads
{
	t_frac		*data;
	pthread_t	threads;
	t_value		*value;
	int			num;
}				t_threads;

void			ft_error(char *str);
void			work_pthreads(t_frac *frac);
void			mandelbrot(t_frac *frac, int x, int y, t_value *value);
int				mouse_hook(int keycode, int x, int y, t_frac *frac);
int				key_hook(int keycode, t_frac *frac);

#endif
