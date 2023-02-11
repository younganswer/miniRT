#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# define INF 1e9
# define EPSILON 0.0001

// render.c
int	render(t_var *var);

// render_sphere.c
double			get_distance_of_sphere(void *content, t_ray ray);
unsigned int	get_color_of_sphere(void *content, t_ray ray);

// render_plane.c
double			get_distance_of_plane(void *content, t_ray ray);
unsigned int	get_color_of_plane(void *content, t_ray ray);

// render_cylinder.c
double			get_distance_of_cylinder(void *content, t_ray ray);
unsigned int	get_color_of_cylinder(void *content, t_ray ray);

#endif