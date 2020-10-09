#ifndef MAP_EDITOR_H

# define MAP_EDITOR_H

# include "../minilibx-linux/mlx.h"
# include "keys_linux.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stdint.h>

# define NAME "map_editor"
# define MX 24
# define MY 24
# define NBS 8
# define PIC_SIZE 33

typedef struct		s_image
{
	void			*pt;
	unsigned char	*data;
}					t_image;

typedef struct		s_control
{
	int mb;
	int mx;
	int my;
}					t_control;

typedef struct		s_app
{
	int				ww;
	int				wh;
	int				sx;
	int				sy;
	void			*mlx;
	void			*win;
	t_image			pic[NBS];
	int				map[MY][MX];
	int 			brush;
	t_control		control;
}					t_app;

// default.c
void	help();
int		default_idle(void *app);
int		default_key_released(int key, void *app);
int		default_key_pressed(int key, void *app);
int		default_mouse_released(int mb, int x, int y, void *app);
int		default_mouse_pressed(int mb, int x, int y, void *app);
int		default_mouse_position(int x, int y, void *g);
// app_init.c
void	app_init(t_app **app, int ww, int wh);

// utils.c
void	zero(t_app *app);
void	aff(int map[MY][MX]);

// quit.c
int		quit_window(void *app);

#endif
