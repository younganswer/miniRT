#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_hit hit);

t_vec3	ambient(t_var *var, t_hit hit)
{
	const t_vec3	obj_color = vec3_div(hit.color, 256.0);
	const t_vec3	light_color = vec3_mul(
			var->alight->color,
			var->alight->ratio / 256.0
			);

	return (vec3_matrix(obj_color, light_color));
}
