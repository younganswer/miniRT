/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:36 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:56:37 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_hit hit);

t_vec3	ambient(t_var *var, t_hit hit)
{
	const t_vec3	obj_color = vec3_div(hit.color, 256.0);
	const t_vec3	light_color = vec3_mul(
			var->alight->color,
			var->alight->ratio / 256.0
			);

	return (vec3_matrix(obj_color, light_color));
}
