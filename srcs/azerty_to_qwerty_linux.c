#include "../includes/map_editor.h"

static int	azerty_to_qwerty_linux_topnum(int key)
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

static int	azerty_to_qwerty_linux_numpad(int key)
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

int			azerty_to_qwerty_linux(int key)
{
	if (key == 'a')
		return ('q');
	else if (key == 'q')
		return ('a');
	else if (key == 'z')
		return ('w');
	else if (key == 'w')
		return ('z');
	else if (key == ',')
		return ('m');
	else if (key == ')')
		return ('_');
	else if (key >= 'a' && key <= 'z')
		return (key);
	else if (key >= K_NUMPAD_7 && key <= K_NUMPAD_0)
		return (azerty_to_qwerty_linux_numpad(key));
	else
		return (azerty_to_qwerty_linux_topnum(key));
}
