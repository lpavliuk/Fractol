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

# define ERR_0 "{green}Usage: {blue}./fractol {yellow}[name of fractol]\n"
# define ERR_1 "{red}Error: {yellow}There isn't this type of fractol!\n"

# define MLX frac->mlx_ptr
# define WIN frac->win_ptr
# define IMG_PTR frac->img_ptr
# define IMG frac->img

# define WIDTH_W 1920
# define HEIGHT_W 1080

typedef struct	s_frac
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img;
	int		bpp;
	int		size_line;
	int		endian;
}				t_frac;

void			ft_error(char *str);
void			mandelbrot(t_frac *frac);

#endif
