#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			specular(t_var *var, t_hit hit);
static double	get_specular(t_ray light, t_ray normal, t_ray camera);

t_vec3	specular(t_var *var, t_hit hit)
{
	t_vec3	contact;
	t_ray	light_ray;
	t_list	*tmp;
	t_light	*light;
	t_vec3	ret;

	ret = (t_vec3){0, 0, 0};
	if (hit.object == NULL)
		return (ret);
	contact = vec3_add(hit.ray.origin, hit.ray.direction);
	tmp = var->lights;
	while (tmp)
	{
		light = (t_light *)tmp->content;
		light_ray = (t_ray){contact, vec3_sub(light->origin, contact)};
		ret = vec3_add(
			ret,
			vec3_mul(get_origin_color(hit.object), get_specular(light_ray, hit.normal, hit.ray) * light->ratio)
		);
		tmp = tmp->next;
	}
	return (ret);
}

static double	get_specular(t_ray light, t_ray normal, t_ray camera)
{
	const t_vec3	light_dir = vec3_unit(light.direction);
	const t_vec3	reflect = vec3_sub(
			vec3_mul(normal.direction, 2 * vec3_dot(light_dir, normal.direction)),
			light_dir
			);
	const double	dot = vec3_dot(vec3_unit(reflect), vec3_unit(camera.direction));

	if (dot < 0)
		return (0);
	return (pow(dot, 100));
}
