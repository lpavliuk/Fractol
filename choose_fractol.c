/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:44:12 by opavliuk          #+#    #+#             */
/*   Updated: 2018/07/07 18:44:13 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		choose_fractol(char *argv, t_frac *frac)
{
	if (!ft_strcmp(argv, "1"))
		FRACTOL = 1;
	else if (!ft_strcmp(argv, "2"))
		FRACTOL = 2;
	else if (!ft_strcmp(argv, "3"))
		FRACTOL = 3;
	else if (!ft_strcmp(argv, "4"))
		FRACTOL = 4;
	else if (!ft_strcmp(argv, "5"))
		FRACTOL = 5;
	else if (!ft_strcmp(argv, "6"))
		FRACTOL = 6;
	else if (!ft_strcmp(argv, "7"))
		FRACTOL = 7;
	else if (!ft_strcmp(argv, "8"))
		FRACTOL = 8;
	else
	{
		ft_printf(ERR_1);
		exit(0);
	}
}

void		change_fractol(int keycode, t_frac *frac)
{
	if (keycode == 18)
		FRACTOL = 1;
	else if (keycode == 19)
		FRACTOL = 2;
	else if (keycode == 20)
		FRACTOL = 3;
	else if (keycode == 21)
		FRACTOL = 4;
	else if (keycode == 23)
		FRACTOL = 5;
	else if (keycode == 22)
		FRACTOL = 6;
	else if (keycode == 26)
		FRACTOL = 7;
	else if (keycode == 28)
		FRACTOL = 8;
}
