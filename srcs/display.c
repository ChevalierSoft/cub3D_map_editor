#include "../includes/map_editor.h"

void	display_filename(t_app *app)
{
	if (app->in == 1)
	{
		mlx_put_image_to_window(app->mlx, app->win, app->background.pt, 0, 0);
		app->in = 0;
	}
	mlx_string_put(app->mlx, app->win,  SPX, SPY, 0xffccff, "file name : ");
	mlx_string_put(app->mlx, app->win,  SPX + 78, SPY, 0xffccff, app->sfile);
	mlx_string_put(app->mlx, app->win,  SPX + 78 + 6 * app->pts + 1, SPY, \
		0xffffff, ".cub");
}

void	display(t_app *app)
{
	int i;
	int j;

	j = 0;
	while (j < app->sy)
	{
		i = 0;
		while (i < app->sx)
		{
			mlx_put_image_to_window(app->mlx, app->win, \
				app->pic[app->map[j][i]].pt, i * (PIC_SIZE + 3), \
				j * (PIC_SIZE + 3));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->pic[app->brush].pt, \
		BPX, BPY);
	if (app->state)
		display_filename(app);
}
