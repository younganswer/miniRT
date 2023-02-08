#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/ray.h"
#include <stdlib.h>

int	render(t_var *var);

int	render(t_var *var)
{
	ft_bzero(var->img->addr, SCREEN_WIDTH * SCREEN_HEIGHT * 4);
	if (render_shape(var) == FALSE)
		return (FALSE);
	mlx_put_image_to_window(var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}
