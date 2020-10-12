#include "../includes/map_editor.h"

int		default_mouse_released(int mb, int x, int y, void *app)
{
	((t_app *)app)->control.mb = 0;
	if (x > BPX && x < BPX + PIC_SIZE && y > BPY && y < BPY + PIC_SIZE)
		((t_app *)app)->brush = (((t_app *)app)->brush + 1) % NBS;
	return (mb);
}

int		default_mouse_pressed(int mb, int x, int y, void *app)
{
	(void)x;
	(void)y;
	((t_app *)app)->control.mb = mb;
	((t_app *)app)->update = 1;
	return (mb);
}

int		default_mouse_position(int x, int y, void *app)
{
	((t_app *)app)->control.mx = x;
	((t_app *)app)->control.my = y;
	// printf("mouse position %d, %d\n", x, y);
	((t_app *)app)->update = 1;
	return (0);
}
