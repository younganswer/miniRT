#include "../../incs/raytracing.h"

t_vec3	ambient(t_var *var, t_hit hit);

t_vec3	ambient(t_var *var, t_hit hit)
{
	return (vec3_mul(hit.color, var->alight->ratio / 256.0));
}
