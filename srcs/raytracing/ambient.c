#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_object *object);

t_vec3	ambient(t_var *var, t_object *object)
{
	return (
		vec3_mul(
			get_origin_color(object),
			var->alight->ratio
		)
	);
}
