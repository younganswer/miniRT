#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <math.h>

t_bool			render_plane(t_var *var, t_plane *plane);
static double	hit_plane(t_plane *plane, t_ray ray);
static size_t	get_plane_color(t_plane *plane, t_ray ray, double t);

t_bool	render_plane(t_var *var, t_plane *plane)
{
	int		row;
	int		col;
	t_ray	ray;
	double	t;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			ray = get_ray(var->camera, row, col);
			t = hit_plane(plane, ray);
			if (0.0 < t)
				var->img->addr[row * SCREEN_WIDTH + col]
					= get_plane_color(plane, ray, t);
			col++;
		}
		row++;
	}
	return (TRUE);
}

static double	hit_plane(t_plane *plane, t_ray ray)
{
	const double	denominator = vec3_dot(plane->normal, ray.direction);
	if (fabs(denominator) > 1e-6)
		return (vec3_dot(vec3_sub(plane->point, ray.origin), plane->normal)
			/ denominator);
	return (-1.0);
}

static size_t	get_plane_color(t_plane *plane, t_ray ray, double t)
{
	size_t	ret;
	t_vec3	unit_dir;

	unit_dir = vec3_unit(
		vec3_sub(
			point_at_parameter(ray, t),
			plane->point
		)
	);
	ret = (int) ((unit_dir.x + 1.0) * 255.999 * 0.5);
	ret = (ret << 8) + (int) ((unit_dir.y + 1.0) * 255.999 * 0.5);
	ret = (ret << 8) + (int) ((unit_dir.z + 1.0) * 255.999 * 0.5);
	return (ret);
}
