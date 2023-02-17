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
static t_vec3	get_color(t_var *var, double row, double col, int idx);
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
	int		i;
	t_vec3	color;

	i = -1;
	color = (t_vec3){0, 0, 0};
	while ((size_t)++i < g_samples)
		color = vec3_add(color, get_color(var, row, col, i));
	color = vec3_div(color, 16);
	if (clamp(&color, 0, 255) == FALSE)
		return (0);
	return (vec3_to_color(color));
}

static t_vec3	get_color(t_var *var, double row, double col, int idx)
{
	const int		row_offset = (idx / 3 - 1);
	const int		col_offset = (idx % 3 - 1);
	const t_ray		ray = primary_ray(
			var->camera,
			row + row_offset * 0.3, col + col_offset * 0.3
			);
	const t_hit		hit = hit_object(var, ray);
	const t_vec3	ret = phong_reflection(var, hit);

	return (vec3_mul(ret, g_weight[row_offset + 1][col_offset + 1]));
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
