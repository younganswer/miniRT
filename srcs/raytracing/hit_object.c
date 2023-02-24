#include "../../incs/raytracing.h"

static double (*const	g_get_distance[3])(void *object, t_ray ray) = {
	get_distance_to_sphere,
	get_distance_to_plane,
	get_distance_to_cylinder,
};

static t_ray (*const	g_get_normal[3])(void *object, t_vec3 contact) = {
	get_normal_of_sphere,
	get_normal_of_plane,
	get_normal_of_cylinder,
};

t_hit			hit_object(t_var *var, t_ray ray);
static t_bool	set_hit(t_hit *hit, t_object *object, double dist, t_ray ray);

t_hit	hit_object(t_var *var, t_ray ray)
{
	t_hit		ret;
	t_list		*tmp;
	t_object	*object;
	double		dist;

	set_hit(&ret, NULL, INF, ray);
	tmp = var->objects;
	while (tmp)
	{
		object = tmp->content;
		dist = g_get_distance[object->shape](object->object, ray);
		if (dist < vec3_length(ret.ray.direction))
			set_hit(&ret, object, dist, ray);
		tmp = tmp->next;
	}
	return (ret);
}

static t_bool	set_hit(t_hit *hit, t_object *object, double dist, t_ray ray)
{
	hit->object = object;
	hit->ray.origin = ray.origin;
	hit->ray.direction = vec3_mul(ray.direction, dist);
	hit->normal = (t_ray){(t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}};
	hit->color = (t_vec3){0, 0, 0};
	if (dist < INF)
	{
		hit->normal = g_get_normal[hit->object->shape](
				hit->object->object,
				vec3_add(hit->ray.origin, hit->ray.direction)
				);
		hit->normal.origin = vec3_add(
				hit->normal.origin,
				vec3_mul(hit->normal.direction, 0.001)
				);
		hit->color = get_color(hit->object);
		hit->type = get_type(hit->object);
	}
	return (TRUE);
}
