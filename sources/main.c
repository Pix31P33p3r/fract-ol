/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:28:43 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 12:41:33 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	pars(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fractol [julia, mandelbrot, mandelbrot_4]");
		return (0);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
		fractol->func = 1;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol->func = 2;
	else if (ft_strcmp(argv[1], "mandelbrot_4") == 0)
		fractol->func = 3;
	else
	{
		ft_putstr("usage: ./fractol [julia, mandelbrot, mandelbrot_4]");
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	pars(argc, argv, fractol);
	fractol->image = malloc(sizeof(t_image));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 1000, 1000, "fractol");
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img,
			&fractol->image->bits_per_pixel,
			&fractol->image->line_length, &fractol->image->endian);
	init_cords(fractol);
	mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win, 2, 0, botton_press, fractol);
	mlx_hook(fractol->win, 17, 0, close_window, fractol);
	mlx_loop_hook(fractol->mlx, render, fractol);
	mlx_loop(fractol->mlx);
}
