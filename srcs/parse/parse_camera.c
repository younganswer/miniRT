#include "../../incs/parse.h"
#include <stdio.h>

t_bool			parse_camera(t_var *var, char **splited);
static t_bool	set_viewport(t_camera *camera, char *fov);
static t_bool	rotate_tranform(t_camera *camera);

t_bool	parse_camera(t_var *var, char **splited)
{
	if (ft_strslen(splited) != 3)
		return (FALSE);
	var->camera = ft_calloc(sizeof(t_camera), 1, "Error: Fail to init camera");
	return (
		parse_vec3(&var->camera->ray.origin, splited[0]) && \
		parse_vec3(&var->camera->ray.direction, splited[1]) && \
		set_viewport(var->camera, splited[2])
	);
}

static t_bool	set_viewport(t_camera *camera, char *fov)
{
	camera->fov = ft_atof(fov);
	camera->ray.direction = vec3_unit(camera->ray.direction);
	camera->aspect_ratio = (double) SCREEN_WIDTH / SCREEN_HEIGHT;
	camera->viewport_height = 2.0;
	camera->viewport_width = camera->aspect_ratio * camera->viewport_height;
	camera->focal_length = 1.0;
	return (rotate_tranform(camera));
}

static t_bool	rotate_tranform(t_camera *camera)
{
	t_vec3	axis_x;
	t_vec3	axis_y;
	t_vec3	axis_z;

	axis_z = vec3_unit(camera->ray.direction);
	axis_x = vec3_unit(vec3_cross((t_vec3){0, 1, 0}, axis_z));
	if (axis_x.x < 0)
		axis_x = vec3_reverse(axis_x);
	axis_y = vec3_cross(axis_z, axis_x);
	if (axis_y.y < 0)
		axis_y = vec3_reverse(axis_y);
	camera->horizontal = vec3_mul(axis_x, camera->viewport_width);
	camera->vertical = vec3_mul(axis_y, camera->viewport_height);
	camera->higher_left_corner = vec3_add(
			camera->ray.origin,
			vec3_add(
				vec3_mul(axis_z, camera->focal_length),
				vec3_sub(
					vec3_div(camera->vertical, 2),
					vec3_div(camera->horizontal, 2)
					)
				)
			);
	return (TRUE);
}
