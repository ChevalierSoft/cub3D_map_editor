#include "../includes/map_editor.h"

int		default_mouse_released(int mb, int x, int y, void *app)
{
	((t_app *)app)->control.mb = 0;
	printf("mouse released\n");
	return (mb);
}

int		default_mouse_pressed(int mb, int x, int y, void *app)
{
	((t_app *)app)->control.mb = mb;
	printf("mouse pressed %d\n", mb);
	return (mb);
}

int		default_mouse_position(int x, int y, void *app)
{
	((t_app *)app)->control.mx = x;
	((t_app *)app)->control.my = y;
	// printf("mouse position %d, %d\n", x, y);
}

int		default_key_pressed(int key, void *app)
{
	if (!((t_app *)app)->state)
	{
		if (key == K_Q)
			((t_app *)app)->brush = 0;
		else if (key == K_W)
			((t_app *)app)->brush = 1;
		else if (key == K_E)
			((t_app *)app)->brush = 2;
		else if (key == K_A)
			((t_app *)app)->brush = 3;
		else if (key == K_S)
			((t_app *)app)->brush = 4;
		else if (key == K_D)
			((t_app *)app)->brush = 5;
		else if (key == K_F)
			((t_app *)app)->brush = 6;
		else if (key == K_SPACE)
			((t_app *)app)->brush = 7;
	}
}

int		default_key_released(int key, void *app)
{
	if (key == K_ESC)
		quit_window(app);
	if (key == K_ENTER)
	{
		if (!((t_app *)app)->state)
			((t_app *)app)->state = 1;
		else
		{
			((t_app *)app)->state = 0;
			((t_app *)app)->pts = 0;
			ft_memset(((t_app *)app)->sfile, '\0', SAVE_FILE_SIZE);
			mlx_clear_window(((t_app *)app)->mlx, ((t_app *)app)->win);
		}
		printf("state : %d\n", ((t_app *)app)->state);
	}
	else if (((t_app *)app)->state == 1)
	{
		printf("%d\n", key);
		if (key == K_BS)
		{
			if (((t_app *)app)->pts > 0)
			{
				((t_app *)app)->pts--;
				((t_app *)app)->sfile[((t_app *)app)->pts] = '\0';
				mlx_clear_window(((t_app *)app)->mlx, ((t_app *)app)->win);
			}
		}
		else
		{
			if (((t_app *)app)->pts < SAVE_FILE_SIZE)
			{
				((t_app *)app)->sfile[((t_app *)app)->pts] = key;
				((t_app *)app)->pts++;
			}
		}
	}
}

void	display(t_app *app)
{
	int i;
	int j;

	j = 0;
	while (j < MY)
	{
		i = 0;
		while (i < MX)
		{
			mlx_put_image_to_window(app->mlx, app->win, \
				app->pic[app->map[j][i]].pt, i * (PIC_SIZE + 3), \
				j * (PIC_SIZE + 3));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->pic[app->brush].pt, \
		1000, 300);
	if (app->state)
		mlx_string_put(app->mlx, app->win,  900, 350, 0xffccff, "file name : ");
	mlx_string_put(app->mlx, app->win,  980, 350, 0xffccff, app->sfile);
}

void	fait_des_trucs(t_app *app)
{
	if (!app->state)
	{
		if (app->control.mb)
		{
			if (app->control.mx > 0 && app->control.mx < (PIC_SIZE + 3) * MX \
				&& app->control.my > 0 && app->control.my < (PIC_SIZE + 3) * MY
			)
			{
				// printf("%dx%d\n", app->control.mx / (PIC_SIZE + 3), \
				// app->control.my / (PIC_SIZE + 3));
				app->map[app->control.my / (PIC_SIZE + 3)] \
				[app->control.mx / (PIC_SIZE + 3)] = app->brush;
			}
		}
	}

}

int		default_idle(void *app)
{
	fait_des_trucs(app);
	display(app);
}
