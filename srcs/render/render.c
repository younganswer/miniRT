#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/raytracing.h"

// const size_t	g_samples = 25;
// const size_t	g_row = 5;
// const size_t	g_col = 5;
// const double	g_weight[5][5] = {
// 	{1.0, 4.0, 6.0, 4.0, 1.0},
// 	{4.0, 16.0, 24.0, 16.0, 4.0},
// 	{6.0, 24.0, 36.0, 24.0, 6.0},
// 	{4.0, 16.0, 24.0, 16.0, 4.0},
// 	{1.0, 4.0, 6.0, 4.0, 1.0}
// };
// const double	g_offset = 0.2;
// const double	g_whole_weight = 256.0;

const size_t	g_samples = 9;
const size_t	g_row = 3;
const size_t	g_col = 3;
const double	g_weight[3][3] = {
	{1.0, 2.0, 1.0},
	{2.0, 4.0, 2.0},
	{1.0, 2.0, 1.0}
};
const double	g_offset = 0.3;
const double	g_whole_weight = 16.0;

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
	color = vec3_div(color, g_whole_weight);
	if (clamp(&color, 0, 255) == FALSE)
		return (0);
	return (vec3_to_color(color));
}

static t_vec3	get_color(t_var *var, double row, double col, int idx)
{
	const int		row_offset = (idx / g_row);
	const int		col_offset = (idx % g_col);
	const t_ray		ray = primary_ray(
			var->camera,
			row + (row_offset - g_row / 2) * g_offset,
			col + (col_offset - g_col / 2) * g_offset
			);
	const t_hit		hit = hit_object(var, ray);
	const t_vec3	ret = phong_reflection(var, hit);

	return (vec3_mul(ret, g_weight[row_offset][col_offset]));
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
