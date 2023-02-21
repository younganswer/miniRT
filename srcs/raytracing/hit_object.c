#include "../../incs/raytracing.h"

static double (*const	g_get_dist_to_object[3])(void *object, t_ray ray) = {
	get_distance_to_sphere,
	get_distance_to_plane,
	get_distance_to_cylinder,
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
		dist = g_get_dist_to_object[object->shape](object->object, ray);
		if (dist < vec3_length(ray.direction))
			set_hit(&ret, object, dist, ray);
		tmp = tmp->next;
	}
	return (ret);
}

static t_bool	set_hit(t_hit *hit, t_object *object, double dist, t_ray ray)
{
	hit->object = object;
	hit->ray.origin = ray.origin;
	hit->ray.direction = vec3_mul(vec3_unit(ray.direction), dist);
	hit->normal = (t_ray){(t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}};
	hit->color = (t_vec3){0, 0, 0};
	if (dist < INF)
	{
		hit->normal = get_normal(hit->object, vec3_add(ray.origin, ray.direction));
		hit->color = get_color(hit->object);
	}
	return (TRUE);
}
