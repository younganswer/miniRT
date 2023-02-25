#include "../../incs/raytracing.h"

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit);

t_vec3	phong_reflection(t_var *var, t_light *light, t_hit hit)
{
	return (
		vec3_add(
			vec3_add(
				diffuse(var, light, hit),
				specular(light, hit)
			),
			ambient(var, hit)
		)
	);
}
