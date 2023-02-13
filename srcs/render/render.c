#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/raytracing.h"

int	render(t_var *var);

int	render(t_var *var)
{
	int		row;
	int		col;
	t_ray	ray;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			ray = primary_ray(var->camera, row, col);
			var->img->addr[row * SCREEN_WIDTH + col]
				= phong_reflection(var, hit_object(var, ray));
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(
		var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}
