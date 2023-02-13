#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_hit hit);
static double	get_diffuse(t_light *light, t_ray normal);

t_vec3	diffuse(t_var *var, t_hit hit)
{
	t_vec3	contact;
	t_ray	normal;
	double	diff;
	t_list	*tmp;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	contact = vec3_add(hit.ray.origin, hit.ray.direction);
	normal = get_normal(hit.object, contact);
	diff = 0;
	tmp = var->lights;
	while (tmp)
	{
		diff += get_diffuse((t_light *)tmp->content, normal);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(hit.object), diff));
}

static double	get_diffuse(t_light *light, t_ray normal)
{
	const t_vec3	light_dir = vec3_sub(light->origin, normal.origin);
	const double	light_dist = vec3_length(light_dir);
	const double	dot = vec3_dot(vec3_unit(light_dir), normal.direction);

	return (fmax(dot, 0) * (light->ratio / (light_dist * light_dist)));
}
