#include "../../incs/parse.h"

t_bool	parse_camera(t_var *var, int fd);

t_bool	parse_camera(t_var *var, int fd)
{
	var->camera = ft_calloc(sizeof(t_camera), 1, "Error: Fail to init camera");
	var->camera->ray = (t_ray){(t_vec3){0, 0, 0}, (t_vec3){1, 0, 0}};
	(void) fd;
	return (TRUE);
}
