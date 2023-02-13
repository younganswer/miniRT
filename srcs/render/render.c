#include "../../libs/libmlx/incs/mlx.h"
#include "../../incs/render.h"
#include "../../incs/raytracing.h"
#include <stdlib.h>
#include <stdio.h>

static double (*const	g_get_dist_of_object[3])(void *shape, t_ray ray) = {
	get_distance_of_sphere,
	get_distance_of_plane,
	get_distance_of_cylinder,
};

static uint (*const		g_get_color_of_object[3])(void *shape, t_ray ray) = {
	get_color_of_sphere,
	get_color_of_plane,
	get_color_of_cylinder,
};

int		render(t_var *var);
uint	get_color(t_var *var, t_ray ray);

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
			var->img->addr[row * SCREEN_WIDTH + col]
				= get_color(var, primary_ray(var->camera, row, col));
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(
		var->mlx->mlx, var->mlx->window, var->img->img, 0, 0);
	return (TRUE);
}

uint	get_color(t_var *var, t_ray ray)
{
	t_list	*tmp;
	t_shape	*shape;
	t_shape	*closest;
	double	dist;
	double	tmp_dist;

	closest = NULL;
	dist = INF;
	tmp = var->shapes;
	while (tmp)
	{
		shape = tmp->content;
		tmp_dist = g_get_dist_of_object[shape->type](shape->shape, ray);
		if (tmp_dist < dist)
		{
			closest = shape;
			dist = tmp_dist;
		}
		tmp = tmp->next;
	}
	if (!closest)
		return (0);
	return (g_get_color_of_object[closest->type](closest->shape, ray));
}
