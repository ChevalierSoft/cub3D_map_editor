#include "../includes/map_editor.h"

int		default_key_pressed(int key, void *app)
{
	// printf("key pressed : %d : %c\n", key, key);
	((t_app *)app)->update = 1;
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
	return (0);
}

void 	writint_file_name(void *app, int key)
{
	((t_app *)app)->in = 1;
	if (key == K_BS)
	{
		if (((t_app *)app)->pts > 0)
		{
			((t_app *)app)->pts--;
			((t_app *)app)->sfile[((t_app *)app)->pts] = '\0';
			// (((t_app *)app)->mlx, \
				((t_app *)app)->win, ((t_app *)app)->background.pt, 0, 0);
		}
	}
	else
	{
		if (((t_app *)app)->pts < SAVE_FILE_SIZE - 5)
		{
			if ((key = get_char_from_key(key)) < 0)
				return ;
			((t_app *)app)->sfile[((t_app *)app)->pts] = key;
			((t_app *)app)->pts++;
		}
	}
}

int		default_key_released(int key, void *app)
{
	((t_app *)app)->update = 1;
	// printf("key : %d %c\n", key, key);
	if (key == K_ESC)
		quit_window(app, "");
	if (key == K_ENTER)
	{
		if (((t_app *)app)->ffs)
			((t_app *)app)->ffs = 0;
		else if (!((t_app *)app)->state)
			((t_app *)app)->state = 1;
		else
		{
			((t_app *)app)->in = 1;
			save_map(app);
			((t_app *)app)->state = 0;
			((t_app *)app)->pts = 0;
			ft_memset(((t_app *)app)->sfile, '\0', SAVE_FILE_SIZE);
			// (((t_app *)app)->mlx, \
				((t_app *)app)->win, ((t_app *)app)->background.pt, 0, 0);
		}
		// printf("state : %d\n", ((t_app *)app)->state);
	}
	else if (((t_app *)app)->state == 1)
		writint_file_name(app, key);
	return (0);
}
