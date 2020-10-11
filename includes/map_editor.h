#ifndef MAP_EDITOR_H

# define MAP_EDITOR_H

# include "../minilibx-linux/mlx.h"
# include "keys_linux.h"
# include "color.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define NAME "map_editor"
# define MX 24
# define MY 24
# define WW 1400
# define WH 900
# define BPX 1148
# define BPY 145
# define SPX 937
# define SPY 827
# define NBS 8
# define PIC_SIZE 33

# define SAVE_FILE_SIZE 30

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
	t_image			background;
	int				map[MY][MX];
	int 			brush;
	t_control		control;
	int				state;
	char			sfile[SAVE_FILE_SIZE];
	int				pts;
	int				in;
	int				ffs;
	int				q;
}					t_app;

// app_init.c
void		app_init(t_app **app, int argc, char **argv);

// azerty_to_qwerty_linux.c
int		azerty_to_qwerty_linux(int key);

// default.c
void	help();
int		default_idle(void *app);
int		default_key_released(int key, void *app);
int		default_key_pressed(int key, void *app);
int		default_mouse_released(int mb, int x, int y, void *app);
int		default_mouse_pressed(int mb, int x, int y, void *app);
int		default_mouse_position(int x, int y, void *g);

// ft_save_map.c
void	save_map(t_app *app);

// utils.c
void	aff(t_app *app);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	print(char *s);
void	zero(t_app *app);

// quit.c
int		quit_window(void *app, char *s);
void	wrong_size(t_app *app);

#endif
