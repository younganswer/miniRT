#include "../../incs/vec3.h"
#include <math.h>

t_vec3	vec3_reverse(t_vec3 vec);
t_vec3	vec3_unit(t_vec3 vec);
double	vec3_length(t_vec3 vec);
double	vec3_length_squared(t_vec3 vec);
uint	vec3_to_color(t_vec3 vec);

t_vec3	vec3_reverse(t_vec3 vec)
{
	return ((t_vec3){-vec.x, -vec.y, -vec.z});
}

t_vec3	vec3_unit(t_vec3 vec)
{
	return (vec3_div(vec, vec3_length(vec)));
}

double	vec3_length(t_vec3 vec)
{
	return (sqrt(vec3_length_squared(vec)));
}

double	vec3_length_squared(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

uint	vec3_to_color(t_vec3 vec)
{
	return ((uint)(vec.x) << 16 | (uint)(vec.y) << 8 | (uint)(vec.z));
}
