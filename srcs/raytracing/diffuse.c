#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_hit hit);
static double	get_diffuse_ratio(t_var *var, t_light *light, t_ray normal);

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
		diffuse_ratio += get_diffuse_ratio(var, (t_light *)tmp->content, hit.normal);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(hit.object), diffuse_ratio));
}

static double	get_diffuse_ratio(t_var *var, t_light *light, t_ray normal)
{
	t_ray	light_ray;
	t_hit	hit;
	double	ret;

	light_ray = (t_ray){
		normal.origin,
		vec3_unit(vec3_sub(light->origin, normal.origin))
	};
	if (vec3_dot(normal.direction, light_ray.direction) < 0)
		normal.direction = vec3_reverse(normal.direction);
	hit = hit_object(var, light_ray);
	if (hit.object != NULL)
		return (0);
	ret = vec3_dot(vec3_unit(normal.direction), vec3_unit(light_ray.direction));
	return (ret * light->ratio);
}
