#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_hit hit);

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
