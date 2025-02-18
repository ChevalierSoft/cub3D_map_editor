/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:49:58 by dait-atm          #+#    #+#             */
/*   Updated: 2020/10/12 13:50:00 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_editor.h"

int	main(int argc, char **argv)
{
	t_app *app;

	app_init(&app, argc, argv);
	mlx_put_image_to_window(((t_app *)app)->mlx, \
		((t_app *)app)->win, ((t_app *)app)->background.pt, 0, 0);
	mlx_loop_hook(app->mlx, &default_idle, app);
	mlx_hook(app->win, 2, 1L << 0, &default_key_pressed, app);
	mlx_hook(app->win, 3, 1L << 1, &default_key_released, app);
	mlx_mouse_hook(app->win, &default_mouse_pressed, app);
	mlx_hook(app->win, 5, 1L << 3, &default_mouse_released, app);
	mlx_hook(app->win, 6, 1L << 6, &default_mouse_position, app);
	mlx_hook(app->win, 17, 1L << 17, &quit_window, app);
	mlx_loop(app->mlx);
	return (0);
}
