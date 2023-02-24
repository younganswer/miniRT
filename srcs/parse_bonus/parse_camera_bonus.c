#include "../../incs/parse.h"
#include "../../incs/err.h"
#include <math.h>

t_bool			parse_camera(t_var *var, char **splited);
static t_bool	parse_fov(t_var *var, double *fov, char *s_fov);
static t_bool	set_viewport(t_camera *camera);
static t_bool	rotate_tranform(t_camera *camera);

t_bool	parse_camera(t_var *var, char **splited)
{
	if (var->camera != NULL)
		return (set_err(var, DUPLICATED_IDENTIFIER) && FALSE);
	if (ft_strslen(splited) != 3)
		return (set_err(var, INVALID_ARG) && FALSE);
	var->camera = ft_calloc(sizeof(t_camera), 1, "Error: Fail to init camera");
	return (
		parse_vec3(&var->camera->ray.origin, splited[0]) && \
		parse_vec3(&var->camera->ray.direction, splited[1]) && \
		dir_range_is_valid(var, var->camera->ray.direction) && \
		parse_fov(var, &var->camera->fov, splited[2]) && \
		set_viewport(var->camera)
	);
}

static t_bool	parse_fov(t_var *var, double *fov, char *s_fov)
{
	*fov = ft_atof(s_fov);
	if (*fov < 0 || *fov > 180)
		return (set_err(var, INVALID_RANGE) && FALSE);
	return (TRUE);
}

static t_bool	set_viewport(t_camera *camera)
{
	const double	aspect_ratio = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;
	const double	viewport_width = tan(camera->fov / 2 * M_PI / 180);
	const double	viewport_height = viewport_width / aspect_ratio;

	camera->ray.direction = vec3_unit(camera->ray.direction);
	camera->horizontal = vec3_mul((t_vec3){1, 0, 0}, viewport_width);
	camera->vertical = vec3_mul((t_vec3){0, 1, 0}, viewport_height);
	return (rotate_tranform(camera));
}

static t_bool	rotate_tranform(t_camera *camera)
{
	t_vec3	axis_x;
	t_vec3	axis_y;
	t_vec3	axis_z;

	axis_z = vec3_unit(camera->ray.direction);
	if (axis_z.x == 0 && axis_z.z == 0)
		axis_x = (t_vec3){1, 0, 0};
	else
		axis_x = vec3_unit(vec3_cross((t_vec3){0, 1, 0}, axis_z));
	if (0 < axis_z.z * axis_x.x)
		axis_x = vec3_reverse(axis_x);
	axis_y = vec3_unit(vec3_cross(axis_z, axis_x));
	if (axis_z.x == 0 && axis_z.z == 0)
		axis_y = (t_vec3){0, 0, 1 - 2 * (axis_z.y < 0)};
	else if (axis_y.y < 0)
		axis_y = vec3_reverse(axis_y);
	camera->horizontal = vec3_mul(axis_x, camera->horizontal.x);
	camera->vertical = vec3_mul(axis_y, camera->vertical.y);
	camera->higher_left_corner = vec3_add(camera->ray.origin,
			vec3_add(vec3_mul(axis_z, 1), vec3_sub(
					vec3_div(camera->vertical, 2),
					vec3_div(camera->horizontal, 2))));
	return (TRUE);
}
