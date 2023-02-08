#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <stdlib.h>

int		render(t_var *var);
size_t	get_color(t_var *var, int row, int col);

int	render(t_var *var)
{
	int	row;
	int	col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			var->img->addr[row * SCREEN_WIDTH + col] = get_color(var, row, col);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}

// Get color of closest object
size_t	get_color(t_var *var, int row, int col)
{
	size_t	ret;

	ret = 0;
	(void) var;
	(void) row;
	(void) col;
	return (ret);
}
