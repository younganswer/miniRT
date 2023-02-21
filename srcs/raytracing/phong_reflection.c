#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit);

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit)
{
	t_vec3	diff;
	t_vec3	spec;
	t_vec3	amb;

	diff = diffuse(var, light, hit);
	spec = specular(light, hit);
	amb = ambient(var, hit);
	return (vec3_add(vec3_add(diff, spec), amb));
}
