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



int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "1"))
			ft_printf("{green}OK - {yellow}1!\n");
		else if (!ft_strcmp(argv[1], "2"))
			ft_printf("{green}OK - {yellow}2!\n");
		else if (!ft_strcmp(argv[1], "3"))
			ft_printf("{green}OK - {yellow}3!\n");
		else
			ft_printf("{red}Error: {yellow}There isn't this type of fractol!\n");
	}
	else
		ft_printf("{green}Usage: {blue}./fractol {yellow}[name of fractol]\n");
	return (0);
}
