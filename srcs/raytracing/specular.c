#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			specular(t_var *var, t_hit hit);
static double	get_specular(t_light *light, t_hit hit);

t_vec3	specular(t_var *var, t_hit hit)
{
	t_list	*tmp;
	t_light	*light;
	t_vec3	ret;

	ret = (t_vec3){0, 0, 0};
	if (hit.object == NULL)
		return (ret);
	tmp = var->lights;
	while (tmp)
	{
		light = tmp->content;
		ret = vec3_add(
			ret,
			vec3_mul(
				get_origin_color(hit.object),
				get_specular(light, hit) * light->ratio
			)
		);
		tmp = tmp->next;
	}
	return (ret);
}

static double	get_specular(t_light *light, t_hit hit)
{
	const t_vec3	contact = vec3_add(hit.ray.origin, hit.ray.direction);
	const t_ray		light_dir = (t_ray){contact, vec3_sub(light->origin, contact)};
	const t_vec3	reflect = vec3_sub(
		vec3_mul(
			hit.normal.direction,
			2 * vec3_dot(hit.normal.direction, light_dir.direction)
		),
		light_dir.direction
	);
	const double	dot = vec3_dot(reflect, vec3_reverse(vec3_unit(hit.ray.direction)));

	if (dot < 0)
		return (0);
	return (pow(fmax(0, dot), 100));
}
