#include "../includes/map_editor.h"

static int	get_key_osx_rebind_3(int key)
{
	if (key == K_B)
		return ('b');
	else if (key == K_V)
		return ('v');
	else if (key == K_K)
		return ('k');
	else if (key == K_J)
		return ('j');
	else if (key == K_X)
		return ('x');
	else if (key == K_Q)
		return ('q');
	else if (key == K_Z)
		return ('z');
	else if (key == K_PARENTESIS_R)
		return ('_');
	return (-1);
}

static int get_key_osx_rebind_2(int key)
{
	if (key == K_C)
		return ('c');
	else if (key == K_U)
		return ('u');
	else if (key == K_M)
		return ('m');
	else if (key == K_W)
		return ('w');
	else if (key == K_F)
		return ('f');
	else if (key == K_G)
		return ('g');
	else if (key == K_Y)
		return ('y');
	else if (key == K_P)
		return ('p');
	return (get_key_osx_rebind_3(key));
}

int			get_key_osx_rebind(int key)
{
	if (key == K_E)
		return ('e');
	else if (key == K_T)
		return ('t');
	else if (key == K_A)
		return ('a');
	else if (key == K_O)
		return ('o');
	else if (key == K_I)
		return ('i');
	else if (key == K_N)
		return ('n');
	else if (key == K_S)
		return ('s');
	else if (key == K_H)
		return ('h');
	else if (key == K_R)
		return ('r');
	else if (key == K_D)
		return ('d');
	else if (key == K_L)
		return ('l');
	return (get_key_osx_rebind_2(key));
}
