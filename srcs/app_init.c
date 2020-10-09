#include "../includes/map_editor.h"

static void	did_you_know_that_i_hate_25_l_by_function(t_app *app)
{
	int		size;

	size = PIC_SIZE;
	app->pic[0].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca0.xpm", &size, &size);
	app->pic[1].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca1.xpm", &size, &size);
	app->pic[2].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca2.xpm", &size, &size);
	app->pic[3].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca3.xpm", &size, &size);
	app->pic[4].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca4.xpm", &size, &size);
	app->pic[5].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca5.xpm", &size, &size);
	app->pic[6].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca6.xpm", &size, &size);
	app->pic[7].pt = mlx_xpm_file_to_image(app->mlx, \
		"pics/ca7.xpm", &size, &size);
}

void	app_init(t_app **app, int ww, int wh)
{
	if (!(*app = malloc(sizeof(t_app))))
		quit_window(app);
	if (!((*app)->mlx = mlx_init()))
	{
		free(*app);
		exit(2);
	}
	if (!((*app)->win = mlx_new_window((*app)->mlx, ww, wh, NAME)))
	{
		free(*app);
		exit(2);
	}
	(*app)->ww = ww;
	(*app)->wh = wh;
	(*app)->brush = 1;
	did_you_know_that_i_hate_25_l_by_function(*app);
	zero(*app);
	aff((*app)->map);
}
