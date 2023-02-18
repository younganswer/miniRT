#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_object *object);

t_vec3	ambient(t_var *var, t_object *object)
{
	if (object->shape == SPHERE)
		return ((t_vec3){0, 0, 0});
	return (
		vec3_mul(
			get_origin_color(object),
			var->alight->ratio
		)
	);
}
