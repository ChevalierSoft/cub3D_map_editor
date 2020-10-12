/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:50:05 by dait-atm          #+#    #+#             */
/*   Updated: 2020/10/12 13:50:06 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_editor.h"

static void	remove_window(t_app *app)
{
	int i;

	mlx_clear_window(app->mlx, app->win);
	i = 0;
	while (i < NBS)
	{
		mlx_destroy_image(app->mlx, app->pic[i].pt);
		i++;
	}
	mlx_destroy_image(app->mlx, app->background.pt);
	mlx_destroy_window(app->mlx, app->win);
	free(app);
}

int			quit_window(void *app, char *s)
{
	print(s);
	remove_window(app);
	exit(0);
}

void		wrong_size(t_app *app)
{
	print(RED "Error\n./map_editor [size] or [sizeX] [sizeY]\n" RST);
	print(RED "             [size] must be between [0 - 24]\n" RST);
	quit_window(app, "");
}
