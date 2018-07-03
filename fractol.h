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

# define MLX frac->mlx_ptr;
# define WIN frac->win_ptr;

typedef struct	s_frac
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_frac;

#endif
