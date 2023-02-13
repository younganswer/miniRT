#include "../../incs/raytracing.h"

t_ray	primary_ray(t_camera *camera, int row, int col);

t_ray	primary_ray(t_camera *camera, int row, int col)
{
	t_ray	ret;

	ret.origin = camera->ray.origin;
	ret.direction = vec3_sub(
			vec3_add(
				camera->higher_left_corner,
				vec3_sub(
					vec3_mul(camera->horizontal,
						(double) col / (SCREEN_WIDTH - 1)),
					vec3_mul(camera->vertical,
						(double) row / (SCREEN_HEIGHT - 1))
					)
				),
			camera->ray.origin
			);
	ret.direction = vec3_unit(ret.direction);
	return (ret);
}
