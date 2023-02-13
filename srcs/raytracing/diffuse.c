#include "../../incs/raytracing.h"
#include <math.h>

t_vec3			diffuse(t_var *var, t_shape *shape, t_ray ray);
static t_ray	get_normal(t_shape *shape, t_vec3 contact);
static double	get_diffuse(t_light *light, t_ray normal);

t_vec3	diffuse(t_var *var, t_shape *shape, t_ray ray)
{
	const t_vec3	contact = vec3_add(ray.origin, ray.direction);
	const t_ray		normal = get_normal(shape, contact);
	double			diff;
	t_list			*tmp;

	diff = 0;
	tmp = var->lights;
	while (tmp)
	{
		diff += get_diffuse((t_light *)tmp->content, normal);
		tmp = tmp->next;
	}
	return (vec3_mul(get_origin_color(shape), diff));
}

static t_ray	get_normal(t_shape *shape, t_vec3 contact)
{
	t_ray	ret;

	if (shape->type == SPHERE)
		ret.direction = vec3_sub(contact, ((t_sphere *)shape->shape)->center);
	else if (shape->type == PLANE)
		ret.direction = ((t_plane *)shape->shape)->normal;
	else if (shape->type == CYLINDER) // TODO
		ret.direction = vec3_sub(contact, ((t_cylinder *)shape->shape)->center);
	ret.origin = contact;
	ret.direction = vec3_unit(ret.direction);
	return (ret);
}

static double	get_diffuse(t_light *light, t_ray normal)
{
	const t_vec3	light_dir = vec3_sub(light->origin, normal.origin);
	const double	light_dist = vec3_length(light_dir);
	const double	dot = vec3_dot(vec3_unit(light_dir), normal.direction);

	return (fmax(dot, 0) * (light->ratio / (light_dist * light_dist)));
}
