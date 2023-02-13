#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_shape *shape);

t_vec3	ambient(t_var *var, t_shape *shape)
{
	return (
		vec3_mul(
			get_origin_color(shape),
			var->alight->ratio
		)
	);
}
