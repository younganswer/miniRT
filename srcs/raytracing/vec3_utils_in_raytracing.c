#include "../../incs/raytracing.h"

uint	vec3_to_color(t_vec3 vec);
t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal);

uint	vec3_to_color(t_vec3 vec)
{
	return ((uint)(vec.x) << 16 | (uint)(vec.y) << 8 | (uint)(vec.z));
}

t_vec3	vec3_reflect(t_vec3 vec, t_vec3 normal)
{
	return (vec3_add(vec3_mul(normal, -2 * vec3_dot(vec, normal)), vec));
}
