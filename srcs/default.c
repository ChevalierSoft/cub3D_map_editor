/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:49:08 by dait-atm          #+#    #+#             */
/*   Updated: 2020/10/12 13:49:10 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_editor.h"

void	fait_des_trucs(t_app *app)
{
	if (!app->state)
	{
		if (app->control.mb)
		{
			if (app->control.mx > 0
				&& app->control.mx < (PIC_SIZE + 3) * app->sx
				&& app->control.my > 0
				&& app->control.my < (PIC_SIZE + 3) * app->sy)
			{
				app->map[app->control.my / (PIC_SIZE + 3)]\
					[app->control.mx / (PIC_SIZE + 3)] = app->brush;
			}
		}
	}
}

int		default_idle(void *app)
{
	if (((t_app *)app)->q)
		wrong_size(app);
	fait_des_trucs(app);
	display(app);
	return (0);
}
