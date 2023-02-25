/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:57:05 by younhwan          #+#    #+#             */
/*   Updated: 2023/02/25 14:57:05 by younhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/raytracing.h"

t_vec3	raytracing(t_var *var, t_hit hit);
t_vec3	get_color(t_object *object);
t_type	get_type(t_object *object);

t_vec3	raytracing(t_var *var, t_hit hit)
{
	t_list	*light;
	t_vec3	ret;

	ret = (t_vec3){0, 0, 0};
	if (hit.object == NULL)
		return (ret);
	light = var->lights;
	while (light)
	{
		if (hit.type == LAMBERTIAN)
			ret = vec3_add(ret, phong_reflection(var, light->content, hit));
		else if (hit.type == DIELECTRIC)
			ret = vec3_add(ret, vec3_mul(
						mirror_reflection(var, light->content, hit, 5), 2.0
						));
		light = light->next;
	}
	return (vec3_mul(ret, 256));
}

t_vec3	get_color(t_object *object)
{
	t_vec3	ret;

	ret = (t_vec3){0, 0, 0};
	if (object->shape == SPHERE)
		ret = ((t_sphere *)object->object)->color;
	else if (object->shape == PLANE)
		ret = ((t_plane *)object->object)->color;
	else if (object->shape == CYLINDER)
		ret = ((t_cylinder *)object->object)->color;
	else if (object->shape == CONE)
		ret = ((t_cone *)object->object)->color;
	return (ret);
}

t_type	get_type(t_object *object)
{
	t_type	ret;

	ret = 0;
	if (object->shape == SPHERE)
		ret = ((t_sphere *)object->object)->type;
	else if (object->shape == PLANE)
		ret = ((t_plane *)object->object)->type;
	else if (object->shape == CYLINDER)
		ret = ((t_cylinder *)object->object)->type;
	else if (object->shape == CONE)
		ret = ((t_cone *)object->object)->type;
	return (ret);
}
