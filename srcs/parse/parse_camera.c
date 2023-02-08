#include "../../incs/parse.h"

t_bool			parse_camera(t_var *var, int fd);
static t_bool	set_var(t_camera *camera, char *line);

t_bool	parse_camera(t_var *var, int fd)
{
	char	*line;

	line = get_next_line_not_empty(fd);
	if (line == NULL)
		return (FALSE);
	var->camera = ft_calloc(sizeof(t_camera), 1, "Error: Fail to init camera");
	return (
		parse_vec3(&var->camera->ray.origin, &line) &&
		parse_vec3(&var->camera->ray.direction, &line) &&
		set_var(var->camera, line)
	);
}

static t_bool	set_var(t_camera *camera, char *line)
{
	camera->fov = ft_atof(line);
	camera->aspect_ratio = (double) SCREEN_WIDTH / SCREEN_HEIGHT;
	camera->viewport_height = 2.0;
	camera->viewport_width = camera->aspect_ratio * camera->viewport_height;
	camera->focal_length = 1.0;
	camera->horizontal = (t_vec3){camera->viewport_width, 0, 0};
	camera->vertical = (t_vec3){0, camera->viewport_height, 0};
	camera->lower_left_corner = vec3_sub(
		vec3_sub(
			vec3_sub(
				camera->ray.origin,
				vec3_div(camera->horizontal, 2)),
			vec3_div(camera->vertical, 2)),
		(t_vec3){0, 0, camera->focal_length}
	);
	return (TRUE);
}
