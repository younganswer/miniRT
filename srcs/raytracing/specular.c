#include "../../incs/raytracing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vec3			specular(t_var *var, t_hit hit);
static double	get_specular_ratio(t_light *light, t_hit hit);

t_vec3	specular(t_var *var, t_hit hit)
{
	t_list	*tmp;
	t_light	*light;
	double	spec_ratio;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	spec_ratio = 0;
	tmp = var->lights;
	while (tmp)
	{
		light = tmp->content;
		spec_ratio += get_specular_ratio(light, hit);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(hit.object), spec_ratio));
}

static double	get_specular_ratio(t_light *light, t_hit hit)
{
	const t_vec3	contact = vec3_add(hit.ray.origin, hit.ray.direction);
	const t_ray		light_ray = (t_ray){
		contact,
		vec3_sub(light->origin, contact)
	};
	const t_vec3	reflect = vec3_sub(
			vec3_mul(
				hit.normal.direction,
				2 * vec3_dot(hit.normal.direction, light_ray.direction)
				),
			light_ray.direction
			);
	const double	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_reverse(vec3_unit(hit.ray.direction))
			);

	if (hit.object->shape == PLANE)
		return (fmax(0, dot) * light->ratio);
	return (pow(fmax(0, dot), 8) * light->ratio * 3);
}
