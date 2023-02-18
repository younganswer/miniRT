#include "../../incs/raytracing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vec3			specular(t_var *var, t_hit hit, int depth);
static t_vec3	get_specular(t_light *light, t_hit hit);
static t_ray	get_reflect(t_hit hit);

t_vec3	specular(t_var *var, t_hit hit, int depth)
{
	t_vec3	ret;
	t_list	*tmp;
	t_hit	next_hit;

	ret = (t_vec3){0, 0, 0};
	if (hit.object == NULL || depth == 0)
		return (ret);
	tmp = var->lights;
	while (tmp)
	{
		next_hit = hit_object(var, get_reflect(hit));
		if (hit.object->shape == PLANE && depth == 5)
			ret = vec3_add(ret, get_specular(tmp->content, hit));
		else if (hit.object->shape == PLANE && depth < 5)
			ret = vec3_add(
					ret,
					vec3_div(vec3_add(diffuse(var, hit), diffuse(var, next_hit)), 2.0));
		else if (hit.object->shape == SPHERE)
			ret = vec3_add(
					ret, vec3_matrix(
						vec3_div(get_origin_color(hit.object), 256.0),
						vec3_mul(specular(var, next_hit, depth - 1), 7.0)));
		tmp = tmp->next;
	}
	return (ret);
}

static t_vec3	get_specular(t_light *light, t_hit hit)
{
	const t_vec3	contact = handle_shadow_acne(
			vec3_add(hit.ray.origin, hit.ray.direction),
			hit.normal.direction
			);
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
	const double	ratio = pow(fmax(0, dot), 10) * light->ratio / 256;

	return (vec3_mul(get_origin_color(hit.object), ratio));
}

static t_ray	get_reflect(t_hit hit)
{
	return ((t_ray){
		handle_shadow_acne(
			vec3_add(hit.ray.origin, hit.ray.direction),
			hit.normal.direction
		),
		vec3_reflect(
			vec3_reverse(hit.ray.direction),
			hit.normal.direction
		)
	});
}
