#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include <stdio.h>
const size_t	g_samples = 9;

unsigned int get_color(t_var *var)
{
    t_object *object = var->objects->content;
    // t_sphere *sphere = object->object;
    // printf("여기 %f\n", sphere->color.y);
    t_plane *plane = object->object;
    printf("여기 %f %f %f\n", plane->color.x, plane->color.y, plane->color.z);
    return 0;
}

int				render(t_var *var)
{
    int i = 0;
    int j = 0;
    while (i < SCREEN_HEIGHT)
    {
        while (j < SCREEN_WIDTH)
        {
            var->img->addr[i * SCREEN_WIDTH + j] = get_color(var);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(
		var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}


