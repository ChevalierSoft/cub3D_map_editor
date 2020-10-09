#include "../includes/map_editor.h"

int     main(int argc, char **argv)
{
    t_app	*app;

	app_init(&app, 1400, 900);

	mlx_loop_hook(app->mlx, &default_idle, app);
	mlx_hook(app->win, 2, 1L<<0, &default_key_pressed, app);
	mlx_hook(app->win, 3, 1L<<1, &default_key_released, app);

	mlx_mouse_hook(app->win, &default_mouse_pressed, app);
	mlx_hook(app->win, 5, 1L<<3, &default_mouse_released, app);

	mlx_hook(app->win, 6, 1L<<6, &default_mouse_position, app);
	mlx_hook(app->win, 17, 1L<<17, &quit_window, app);
	mlx_loop(app->mlx);

	// ENTERWINDOWMASK (1L<<4)

    return (0);
}
