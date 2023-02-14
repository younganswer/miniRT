#include "../../incs/raytracing.h"

static double (*const	g_get_dist_to_object[3])(void *object, t_ray ray) = {
	get_distance_to_sphere,
	get_distance_to_plane,
	get_distance_to_cylinder,
};

t_hit	hit_object(t_var *var, t_ray ray);

t_hit	hit_object(t_var *var, t_ray ray)
{
	t_hit		ret;
	t_list		*tmp;
	t_object	*object;
	double		dist;
	double		tmp_dist;

	ret.object = NULL;
	dist = INF;
	tmp = var->objects;
	while (tmp)
	{
		object = tmp->content;
		tmp_dist = g_get_dist_to_object[object->shape](object->object, ray);
		if (tmp_dist < dist)
		{
			ret.object = object;
			dist = tmp_dist;
		}
		tmp = tmp->next;
	}
	ray.direction = vec3_mul(ray.direction, dist);
	ret.ray = ray;
	ret.normal = get_normal(ret.object, vec3_add(ray.origin, ray.direction));
	if (ret.object->shape == PLANE && 0 < vec3_dot(ret.normal.direction, ray.direction))
		ret.normal.direction = vec3_reverse(ret.normal.direction);
	return (ret);
}
