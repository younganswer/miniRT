#include "../../incs/raytracing.h"

uint	phong_reflection(t_var *var, t_shape *shape, t_ray ray);
t_vec3	get_origin_color(t_shape *shape);

uint	phong_reflection(t_var *var, t_shape *shape, t_ray ray)
{
	const t_vec3	diff = diffuse(var, shape, ray);
	const t_vec3	spec = specular(var, shape, ray, 0);
	const t_vec3	amb = ambient(var, shape);
	const t_vec3	ret = vec3_add(vec3_add(diff, spec), amb);

	return ((uint)ret.x << 16 | (uint)ret.y << 8 | (uint)ret.z);
}

t_vec3	get_origin_color(t_shape *shape)
{
	t_vec3	ret;

	if (shape->type == SPHERE)
		ret = ((t_sphere *)shape->shape)->color;
	else if (shape->type == PLANE)
		ret = ((t_plane *)shape->shape)->color;
	else if (shape->type == CYLINDER)
		ret = ((t_cylinder *)shape->shape)->color;
	return (ret);
}
