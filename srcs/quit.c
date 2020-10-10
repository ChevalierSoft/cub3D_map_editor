#include "../includes/map_editor.h"

static void	remove_window(t_app *app)
{
	int i;

	i = 0;
	while (i < NBS)
	{
		mlx_destroy_image(app->mlx, app->pic[i].pt);
		i++;
	}
	mlx_destroy_image(app->mlx, app->background.pt);
	mlx_clear_window(app->mlx, app->win);
	mlx_destroy_window(app->mlx, app->win);
	free(app);
}

int			quit_window(void *app, char *s)
{
	print(s);
	remove_window(app);
	exit(0);
}
