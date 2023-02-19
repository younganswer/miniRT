#include "../../incs/raytracing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_vec3	specular(t_light *light, t_hit hit);

t_vec3	specular(t_light *light, t_hit hit)
{
	t_vec3	contact;
	t_ray	light_ray;
	t_vec3	reflect;
	double	dot;
	double	ratio;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	contact = handle_shadow_acne(
			vec3_add(hit.ray.origin, hit.ray.direction),
			hit.normal.direction
			);
	light_ray = (t_ray){contact, vec3_sub(light->origin, contact)};
	reflect = vec3_reflect(
			light_ray.direction,
			hit.normal.direction
			);
	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_reverse(vec3_unit(hit.ray.direction))
			);
	ratio = pow(fmax(0, dot), 10) * light->ratio / 256;
	return (vec3_mul(get_color(hit.object), ratio));
}
