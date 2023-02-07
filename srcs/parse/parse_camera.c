#include "../../incs/parse.h"

t_bool	parse_camera(t_var *var, int fd);

t_bool	parse_camera(t_var *var, int fd)
{
	var->camera = ft_calloc(sizeof(t_camera), 1, "Error: Fail to init camera");
	var->camera->ray = (t_ray){(t_vec3){0, 0, 0}, (t_vec3){1, 0, 0}};
	var->camera->aspect_ratio = (double) SCREEN_WIDTH / SCREEN_HEIGHT;
	var->camera->viewport_height = 2.0;
	var->camera->viewport_width = var->camera->aspect_ratio
		* var->camera->viewport_height;
	var->camera->focal_length = 1.0;
	var->camera->horizontal = (t_vec3){var->camera->viewport_width, 0, 0};
	var->camera->vertical = (t_vec3){0, var->camera->viewport_height, 0};
	var->camera->lower_left_corner = vec3_sub(
		vec3_sub(
			vec3_sub(
				var->camera->ray.origin,
				vec3_div(var->camera->horizontal, 2)),
			vec3_div(var->camera->vertical, 2)),
		(t_vec3){0, 0, var->camera->focal_length}
	);
	var->camera->fov = 66.8;
	(void) fd;
	return (TRUE);
}
