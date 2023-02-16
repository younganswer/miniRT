#include "../../incs/raytracing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vec3			specular(t_var *var, t_hit hit, int depth);
static double	get_specular_ratio(t_light *light, t_hit hit);

t_vec3	specular(t_var *var, t_hit hit, int depth)
{
	t_vec3	ret;
	t_list	*tmp;
	t_light	*light;
	t_ray	reflect;

	if (hit.object == NULL || depth == 0)
		return ((t_vec3){0, 0, 0});
	if (hit.object->shape == PLANE)
		return (diffuse(var, hit));
	ret = get_origin_color(hit.object);
	tmp = var->lights;
	while (tmp)
	{
		light = tmp->content;
		reflect = (t_ray) {
			vec3_add(hit.ray.origin, hit.ray.direction),
			vec3_unit(vec3_reflect(
				vec3_reverse(hit.ray.direction), hit.normal.direction))
		};
		reflect = handle_shadow_acne(reflect);
		ret = vec3_matrix(ret, specular(var, hit_object(var, reflect), depth - 1));
		ret = vec3_add(ret, vec3_mul(get_origin_color(hit.object), get_specular_ratio(light, hit)));
		tmp = tmp->next;
	}
	return (ret);
}

static double	get_specular_ratio(t_light *light, t_hit hit)
{
	const t_vec3	contact = vec3_add(hit.ray.origin, hit.ray.direction);
	const t_ray		light_ray = (t_ray){
		contact,
		vec3_sub(light->origin, contact)
	};
	const t_vec3	reflect = vec3_reflect(
			light_ray.direction,
			hit.normal.direction
			);
	const double	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_reverse(vec3_unit(hit.ray.direction))
			);

	if (hit.object->shape == PLANE)
		return (fmax(0, dot) * light->ratio);
	return (pow(fmax(0, dot), 8) * light->ratio);
}
