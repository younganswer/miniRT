#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/raytracing.h"

const size_t	g_samples = 9;
const size_t	g_weight[3][3] = {
{1, 2, 1},
{2, 4, 2},
{1, 2, 1}
};

int				render(t_var *var);
uint			anti_aliasing(t_var *var, double row, double col);
static t_bool	clamp(t_vec3 *ret, uint min, uint max);

int	render(t_var *var)
{
	int		row;
	int		col;

	row = -1;
	while (++row < SCREEN_HEIGHT)
	{
		col = -1;
		while (++col < SCREEN_WIDTH)
			var->img->addr[row * SCREEN_WIDTH + col]
				= anti_aliasing(var, row, col);
	}
	mlx_put_image_to_window(
		var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}

uint	anti_aliasing(t_var *var, double row, double col)
{
	size_t	i;
	int		row_offset;
	int		col_offset;
	t_vec3	color;
	t_ray	ray;

	i = 0;
	color = (t_vec3){0, 0, 0};
	while (i < g_samples)
	{
		row_offset = (i / 3 - 1);
		col_offset = (i % 3 - 1);
		ray = primary_ray(
				var->camera, row + row_offset * 0.3, col + col_offset * 0.3
				);
		color = vec3_add(
				color,
				vec3_mul(
					phong_reflection(var, hit_object(var, ray)),
					g_weight[row_offset + 1][col_offset + 1]
					)
				);
		i++;
	}
	color = vec3_div(color, 16);
	if (clamp(&color, 0, 255) == FALSE)
		return (0);
	return (vec3_to_color(color));
}

static t_bool	clamp(t_vec3 *ret, uint min, uint max)
{
	if (ret->x < min)
		ret->x = min;
	else if (ret->x > max)
		ret->x = max;
	if (ret->y < min)
		ret->y = min;
	else if (ret->y > max)
		ret->y = max;
	if (ret->z < min)
		ret->z = min;
	else if (ret->z > max)
		ret->z = max;
	return (TRUE);
}
