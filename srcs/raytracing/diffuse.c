#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_hit hit);
static double	get_diffuse_ratio(t_var *var, t_light *light, t_hit hit);

t_vec3	diffuse(t_var *var, t_hit hit)
{
	double	diffuse_ratio;
	t_list	*tmp;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	diffuse_ratio = 0;
	tmp = var->lights;
	while (tmp)
	{
		diffuse_ratio += get_diffuse_ratio(var, tmp->content, hit);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(hit.object), diffuse_ratio));
}

static double	get_diffuse_ratio(t_var *var, t_light *light, t_hit hit)
{
	t_ray	normal_ray;
	t_ray	light_ray;
	t_hit	next_hit;
	double	ret;

	normal_ray = (t_ray) {
		vec3_add(
			hit.normal.origin,
			vec3_mul(hit.normal.direction, 0.0001)
		),
		hit.normal.direction
	};
	light_ray = (t_ray){
		normal_ray.origin,
		vec3_unit(vec3_sub(light->origin, normal_ray.origin))
	};
	ret = vec3_dot(normal_ray.direction, light_ray.direction) * light->ratio;
	if (ret <= 0)
		return (0);
	next_hit = hit_object(var, light_ray);
	if (next_hit.object != NULL)
		return (0);
	return (ret);
}
