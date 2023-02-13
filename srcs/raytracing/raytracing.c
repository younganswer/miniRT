#include "../../incs/raytracing.h"

uint	phong_reflection(t_var *var, t_hit hit);
t_vec3	get_origin_color(t_object *object);

uint	phong_reflection(t_var *var, t_hit hit)
{
	t_vec3	diff;
	t_vec3	spec;
	t_vec3	amb;
	t_vec3	ret;

	if (hit.object == NULL)
		return (0);
	diff = diffuse(var, hit.object, hit.ray);
	spec = specular(var, hit.object, hit.ray, 0);
	amb = ambient(var, hit.object);
	ret = vec3_add(vec3_add(diff, spec), amb);
	return ((uint)ret.x << 16 | (uint)ret.y << 8 | (uint)ret.z);
}

t_vec3	get_origin_color(t_object *object)
{
	t_vec3	ret;

	if (object->shape == SPHERE)
		ret = ((t_sphere *)object->object)->color;
	else if (object->shape == PLANE)
		ret = ((t_plane *)object->object)->color;
	else if (object->shape == CYLINDER)
		ret = ((t_cylinder *)object->object)->color;
	return (ret);
}
