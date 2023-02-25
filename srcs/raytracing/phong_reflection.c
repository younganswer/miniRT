/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:56:58 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:56:59 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit);

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit)
{
	return (
		vec3_add(
			vec3_add(
				diffuse(var, light, hit),
				specular(light, hit)
			),
			ambient(var, hit)
		)
	);
}
