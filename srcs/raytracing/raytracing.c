#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_hit hit);
t_vec3	get_origin_color(t_object *object);
t_vec3	handle_shadow_acne(t_vec3 origin, t_vec3 direction);

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
	return (vec3_mul(vec3_add(vec3_add(diff, spec), amb), 256.0));
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

t_vec3	handle_shadow_acne(t_vec3 origin, t_vec3 direction)
{
	return (
		vec3_add(
			origin,
			vec3_mul(
				direction,
				0.0001
			)
		)
	);
}
