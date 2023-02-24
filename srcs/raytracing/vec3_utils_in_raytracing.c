#include "../../incs/raytracing.h"

UINT	vec3_to_color(t_vec3 vec);
t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal);

UINT	vec3_to_color(t_vec3 vec)
{
	return ((UINT)(vec.x) << 16 | (UINT)(vec.y) << 8 | (UINT)(vec.z));
}

t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal)
{
	return (vec3_sub(vec3_mul(normal, 2 * vec3_dot(vec, normal)), vec));
}
