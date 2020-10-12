#include "../includes/map_editor.h"

static int	get_char_from_key_topnum(int key)
{
	if (key == K_TOPNUM_0)
		return ('0');
	else if (key == K_TOPNUM_1)
		return ('1');
	else if (key == K_TOPNUM_2)
		return ('2');
	else if (key == K_TOPNUM_3)
		return ('3');
	else if (key == K_TOPNUM_4)
		return ('4');
	else if (key == K_TOPNUM_5)
		return ('5');
	else if (key == K_TOPNUM_6)
		return ('6');
	else if (key == K_TOPNUM_7)
		return ('7');
	else if (key == K_TOPNUM_8)
		return ('8');
	else if (key == K_TOPNUM_9)
		return ('9');
	return (-1);
}

static int	get_char_from_key_numpad(int key)
{
	if (key == K_NUMPAD_0)
		return ('0');
	else if (key == K_NUMPAD_1)
		return ('1');
	else if (key == K_NUMPAD_2)
		return ('2');
	else if (key == K_NUMPAD_3)
		return ('3');
	else if (key == K_NUMPAD_4)
		return ('4');
	else if (key == K_NUMPAD_5)
		return ('5');
	else if (key == K_NUMPAD_6)
		return ('6');
	else if (key == K_NUMPAD_7)
		return ('7');
	else if (key == K_NUMPAD_8)
		return ('8');
	else if (key == K_NUMPAD_9)
		return ('9');
	return (-1);
}

int			get_key_rebind_linux(int key)
{
	if (key == K_A)
		return ('q');
	else if (key == K_Q)
		return ('a');
	else if (key == K_Z)
		return ('w');
	else if (key == K_W)
		return ('z');
	else if (key == K_COMMA)
		return ('m');
	else if (key == K_PARENTESIS_R)
		return ('_');
	else if (key >= 'a' && key <= 'z')
		return (key);
	return (-1);
}

int			get_char_from_key(int key)
{
	int low_parry;

#ifdef LINUX
	if ((low_parry = get_key_rebind_linux(key)) >= 0)
		return (low_parry);
#endif
#ifdef OSX
	if ((low_parry = get_key_osx_rebind(key)) >= 0)
		return (low_parry);
#endif
	if (key >= K_NUMPAD_7 && key <= K_NUMPAD_0)
		return (get_char_from_key_numpad(key));
	else if (key == K_SPACE)
		return (' ');
	return (get_char_from_key_topnum(key));
}
