#include "../../incs/event.h"
#include <stdlib.h>

int key_pressed(int key, t_var *var);
int key_released(int key, t_var *var);

int	key_pressed(int keycode, t_var *var)
{
	if (keycode == KEY_ESC)
		exit(0);
	(void) var;
	return (0);
}

int	key_released(int keycode, t_var *var)
{
	(void) keycode;
	(void) var;
	return (0);
}
