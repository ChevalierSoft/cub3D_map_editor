/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:07:49 by dait-atm          #+#    #+#             */
/*   Updated: 2020/10/12 14:07:50 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H

# define MAP_EDITOR_H

# include "../minilibx-linux/mlx.h"
# ifdef LINUX
#  include "keys_linux.h"
# else
#  include "keys_osx.h"
# endif
# include "color.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define NAME "chevaliersoft/map_editor"
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

# ifdef LINUX
#  define FONT_SIZE 6
# else
#  define FONT_SIZE 7
# endif

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
	int				brush;
	t_control		control;
	int				state;
	char			sfile[SAVE_FILE_SIZE];
	int				pts;
	int				in;
	int				ffs;
	int				q;
	int				update;
}					t_app;

void				app_init(t_app **app, int argc, char **argv);

int					get_char_from_key(int key);

int					get_key_osx_rebind(int key);

void				help();
int					default_idle(void *app);
int					default_key_released(int key, void *app);
int					default_key_pressed(int key, void *app);
int					default_mouse_released(int mb, int x, int y, void *app);
int					default_mouse_pressed(int mb, int x, int y, void *app);
int					default_mouse_position(int x, int y, void *g);

int					default_mouse_released(int mb, int x, int y, void *app);
int					default_mouse_pressed(int mb, int x, int y, void *app);
int					default_mouse_position(int x, int y, void *app);

void				display(t_app *app);

void				save_map(t_app *app);

void				aff(t_app *app);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				print(char *s);
void				zero(t_app *app);

int					quit_window(void *app, char *s);
void				wrong_size(t_app *app);

#endif
