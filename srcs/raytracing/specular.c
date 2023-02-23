#include "../../incs/raytracing.h"
#include <math.h>

t_vec3	specular(t_light *light, t_hit hit);

t_vec3	specular(t_light *light, t_hit hit)
{
	const t_ray		light_ray = (t_ray){
		hit.normal.origin,
		vec3_sub(light->origin, hit.normal.origin)
	};
	const t_vec3	reflect = vec3_reflect(
			light_ray.direction,
			hit.normal.direction
			);
	const double	dot = vec3_dot(
			vec3_unit(reflect),
			vec3_unit(vec3_reverse(hit.ray.direction))
			);
	const double	ratio = pow(fmax(0, dot), 10) * light->ratio;

	return (vec3_mul(vec3_div(hit.color, 256), ratio));
}
