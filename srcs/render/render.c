#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <stdlib.h>

int				render(t_var *var);
static t_bool	set_background(t_var *var);
static int		get_background_color(t_camera *camera, int row, int col);
static t_bool	clean_img(unsigned int *addr);

int	render(t_var *var)
{
	if (clean_img(var->img->addr) == FALSE ||
		render_shape(var) == FALSE ||
		set_background(var) == FALSE)
		return (FALSE);
	mlx_put_image_to_window(var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}


static t_bool	set_background(t_var *var)
{
	int	row;
	int	col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			if (var->img->addr[row * SCREEN_WIDTH + col] == 0)
				var->img->addr[row * SCREEN_WIDTH + col]
					= get_background_color(var->camera, row, col);
			col++;
		}
		row++;
	}
	return (TRUE);
}

int	get_background_color(t_camera *camera, int row, int col)
{
	int		ret;
	t_ray	ray;
	t_vec3	dir;
	double	t;

	ray = get_ray(camera, row, col);
	dir = vec3_unit(ray.direction);
	t = 0.5 * (dir.y + 1.0);
	ret = (int) ((1.0 - 0.5 * t) * 255.999);
	ret = (ret << 8) + (int) ((1.0 - 0.3 * t) * 255.999);
	ret = (ret << 8) + (int) 255.999;
	return (ret);
}

static t_bool	clean_img(unsigned int *addr)
{
	int	row;
	int	col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			addr[row * SCREEN_WIDTH + col] = 0;
			col++;
		}
		row++;
	}
	return (TRUE);
}
