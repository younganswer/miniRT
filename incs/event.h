#ifndef EVENT_H
# define EVENT_H

# include "structs.h"

typedef enum e_keycode
{
	KEY_ESC = 53,
}	t_keycode;

// key_event.c
int	key_pressed(int key, t_var *var);

#endif