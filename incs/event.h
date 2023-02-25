/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:43:42 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 15:43:43 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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