#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_hit hit);
static double	get_diffuse(t_light *light, t_ray normal);

t_vec3	diffuse(t_var *var, t_hit hit)
{
	double	diff;
	t_list	*tmp;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	diff = 0;
	tmp = var->lights;
	while (tmp)
	{
		diff += get_diffuse((t_light *)tmp->content, hit.normal);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(hit.object), diff));
}

static double	get_diffuse(t_light *light, t_ray normal)
{
	const t_vec3	light_dir = vec3_sub(light->origin, normal.origin);
	const double	dot = vec3_dot(vec3_unit(light_dir), normal.direction);

	return (fmax(dot, 0) * (light->ratio));
}
