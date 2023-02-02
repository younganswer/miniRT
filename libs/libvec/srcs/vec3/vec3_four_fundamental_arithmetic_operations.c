#include "../../incs/vec3.h"

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul(t_vec3 v, double scalar);
t_vec3	vec3_div(t_vec3 v, double scalar);

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2)
{
	return ((t_vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec3	vec3_mul(t_vec3 v, double scalar)
{
	return ((t_vec3){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vec3	vec3_div(t_vec3 v, double scalar)
{
	if (scalar == 0)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){v.x / scalar, v.y / scalar, v.z / scalar});
}
