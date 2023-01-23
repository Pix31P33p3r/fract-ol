/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:57:01 by elel-yak          #+#    #+#             */
/*   Updated: 2023/01/23 10:03:05 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_render(void)
{
	mlx_destroy_image(fractol->mlx, fractol->image->img);
	fractol->image->img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->image->addr = mlx_get_data_addr(fractol->image->img,
			&fractol->image->bits_per_pixel, &fractol->image->line_length,
			&fractol->image->endian);
}

int	render(t_fractol *fractol)
{
	t_render	render;

	render.a = 0;
	init_render();
	while (render.a < 1000)
	{
		render.x = (((render.a / 1000.0) * (fractol->plan.x_max - fractol->plan.x_min)) + fractol->plan.x_min);
		render.b = 0;
		while (render.b < 1000)
		{
			render.y = (((-(render.b) / 1000.0) * (fractol->plan.y_max - fractol->plan.y_min))
					+ fractol->plan.y_max);
			render.i = mandelbrot(render.x, render.y);
			if (render.i < MAX_ITER)
				my_mlx_pixel_put(fractol, render.a, render.b, get_color(render.i % 45));
			else
				my_mlx_pixel_put(fractol, render.a, render.b, 0);
			render.b++;
		}
		render.a++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image->img, 0, 0);
	return (0);
}