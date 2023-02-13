#include "../../incs/raytracing.h"

t_ray	primary_ray(t_camera *camera, int row, int col);
t_ray	get_normal(t_object *object, t_vec3 contact);

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

t_ray	get_normal(t_object *object, t_vec3 contact)
{
	t_ray	ret;

	if (object->shape == SPHERE)
		ret.direction = vec3_sub(contact, ((t_sphere *)object->object)->center);
	else if (object->shape == PLANE)
		ret.direction = ((t_plane *)object->object)->normal;
	else if (object->shape == CYLINDER) // TODO
		ret.direction = vec3_sub(contact, ((t_cylinder *)object->object)->center);
	ret.origin = contact;
	ret.direction = vec3_unit(ret.direction);
	return (ret);
}
