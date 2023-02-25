/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:32 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:55:33 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/err.h"

t_bool	set_err(t_var *var, t_err err);

t_bool	set_err(t_var *var, t_err err)
{
	var->err = err;
	return (TRUE);
}
