#include "../../incs/render.h"

double	hit_cylinder(t_cylinder *cylinder, t_ray ray);
size_t	get_color_of_cylinder(t_cylinder *cylinder, t_ray ray, double t);

double	hit_cylinder(t_cylinder *cylinder, t_ray ray)
{
	(void) cylinder;
	(void) ray;
	return (0.0);
}

size_t	get_color_of_cylinder(t_cylinder *cylinder, t_ray ray, double t)
{
	(void) cylinder;
	(void) ray;
	(void) t;
	return (0);
}
