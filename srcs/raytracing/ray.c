/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:02 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:57:03 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/raytracing.h"

t_ray	primary_ray(t_camera *camera, double row, double col);

t_ray	primary_ray(t_camera *camera, double row, double col)
{
	t_ray	ret;

	ret.origin = camera->ray.origin;
	ret.direction = vec3_sub(
			vec3_add(
				camera->higher_left_corner,
				vec3_sub(
					vec3_mul(camera->horizontal,
						col / (SCREEN_WIDTH - 1)),
					vec3_mul(camera->vertical,
						row / (SCREEN_HEIGHT - 1))
					)
				),
			camera->ray.origin
			);
	ret.direction = vec3_unit(ret.direction);
	return (ret);
}
