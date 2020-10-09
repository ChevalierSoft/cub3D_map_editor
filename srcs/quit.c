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
	mlx_clear_window(app->mlx, app->win);
	mlx_destroy_window(app->mlx, app->win);
	free(app);
}

int			quit_window(void *app)
{
	remove_window(app);
	printf("quit\n");
	exit(0);
}
