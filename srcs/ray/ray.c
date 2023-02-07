#include "../../incs/ray.h"

t_ray	get_ray(t_camera *camera, int row, int col);

t_ray	get_ray(t_camera *camera, int row, int col)
{
	t_ray	ret;

	ret.origin = camera->ray.origin;
	ret.direction = vec3_sub(
		vec3_add(
			camera->lower_left_corner,
			vec3_add(
				vec3_mul(camera->horizontal, (double) col / (SCREEN_WIDTH - 1)),
				vec3_mul(camera->vertical, (double) (SCREEN_HEIGHT - row) / (SCREEN_HEIGHT - 1))
			)
		),
		camera->ray.origin
	);
	return (ret);
}
