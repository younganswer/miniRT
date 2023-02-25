/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:37 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:55:38 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/event.h"
#include <stdlib.h>

int	key_pressed(int key, t_var *var);

int	key_pressed(int keycode, t_var *var)
{
	if (keycode == KEY_ESC)
		exit(0);
	(void) var;
	return (0);
}
