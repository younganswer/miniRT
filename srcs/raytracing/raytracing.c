#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_hit hit);
t_vec3	get_origin_color(t_object *object);
t_ray	handle_shadow_acne(t_ray ray);

t_vec3	phong_reflection(t_var *var, t_hit hit)
{
	t_vec3	diff;
	t_vec3	spec;
	t_vec3	amb;

	if (hit.object == NULL)
		return ((t_vec3){0, 0, 0});
	diff = diffuse(var, hit);
	spec = specular(var, hit, 5);
	amb = ambient(var, hit.object);
	return (vec3_add(vec3_add(diff, spec), amb));
}

t_vec3	get_origin_color(t_object *object)
{
	t_vec3	ret;

	ret = (t_vec3){0, 0, 0};
	if (object->shape == SPHERE)
		ret = ((t_sphere *)object->object)->color;
	else if (object->shape == PLANE)
		ret = ((t_plane *)object->object)->color;
	else if (object->shape == CYLINDER)
		ret = ((t_cylinder *)object->object)->color;
	return (ret);
}

t_ray	handle_shadow_acne(t_ray ray)
{
	t_ray	ret;

	ret = ray;
	ret.origin = vec3_add(ret.origin, vec3_mul(ret.direction, 0.0001));
	return (ret);
}
