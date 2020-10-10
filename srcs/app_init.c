#include "../includes/map_editor.h"

static void	wrong_size(t_app *app)
{
	print(RED "Error\n./map_editor [size] or [sizeX] [sizeY]\n" RST);
	print(RED "             [size] must be between [0 - 24]\n" RST);
	quit_window(app, "");
}

static void	set_map_size(t_app *app, int argc, char **argv)
{
	int ix;
	int iy;

	if (argc < 2)
		wrong_size(app);
	else if (argc == 2)
	{
		if ((ix = ft_atoi(argv[1])) > 0 && ix <= MX)
		{
			app->sx = ix;
			app->sy = ix;
		}
		else
			wrong_size(app);
	}
	else
		if ((ix = ft_atoi(argv[1])) > 0 && (iy = ft_atoi(argv[2])) > 0
			&& ix <= MX && iy <= MY)
		{
			app->sx = ix;
			app->sy = iy;
		}
		else
			wrong_size(app);
}

static void	did_you_know_that_i_hate_25_l_by_function(t_app *app)
{
	int		size;

	ft_memset((app)->sfile, '\0', SAVE_FILE_SIZE);
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
	app->in = 0 ;
}

void		app_init(t_app **app, int argc, char **argv)
{
	if (!(*app = malloc(sizeof(t_app))))
		exit(2);
	if (!((*app)->mlx = mlx_init()))
	{
		free(*app);
		exit(3);
	}
	if (!((*app)->win = mlx_new_window((*app)->mlx, WW, WH, NAME)))
	{
		free(*app);
		exit(4);
	}
	(*app)->ww = WW;
	(*app)->wh = WH;
	(*app)->sx = MX;
	(*app)->sy = MY;
	(*app)->brush = 1;
	(*app)->state = 1;
	(*app)->pts = 0;
	(*app)->control.mb = 0;
	(*app)->control.mx = 0;
	(*app)->control.my = 0;
	did_you_know_that_i_hate_25_l_by_function(*app);
	zero(*app);
	set_map_size(*app, argc, argv);
	printf("sx sy (%d, %d)\n", (*app)->sx, (*app)->sy);
}
