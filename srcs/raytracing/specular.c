#include "../../incs/raytracing.h"

t_vec3			specular(t_var *var, t_object *object, t_ray ray, int depth);
static t_ray	get_reflect(t_ray light, t_ray normal);

t_vec3	specular(t_var *var, t_object *object, t_ray ray, int depth)
{
	const t_vec3	contact = vec3_add(ray.origin, ray.direction);
	const t_ray		normal = get_normal(object, contact);
	t_ray			light;
	t_list			*tmp;
	t_vec3			ret;

	ret = (t_vec3){0, 0, 0};
	if (depth == 5)
		return (ret);
	tmp = var->lights;
	while (tmp)
	{
		light = (t_ray){((t_light *)tmp->content)->origin, vec3_sub(light.origin, contact)};
		tmp = tmp->next;
	}
	return (ret);
}

static t_ray	get_reflect(t_ray light, t_ray normal)
{
	const double	dot = vec3_dot(light.direction, normal.direction);
	const t_vec3	reflect = vec3_sub(
			vec3_mul(normal.direction, 2 * dot),
			light.direction
			);

	return ((t_ray){light.origin, reflect});
}
