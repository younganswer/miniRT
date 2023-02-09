#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# define INF 1e9
# define EPSILON 0.0001

// render.c
int	render(t_var *var);

// render_sphere.c
double	get_distance_of_sphere(t_sphere *sphere, t_ray ray);
size_t	get_color_of_sphere(t_sphere *sphere, t_ray ray);

// render_plane.c
double	get_distance_of_plane(t_plane *plane, t_ray ray);
size_t	get_color_of_plane(t_plane *plane, t_ray ray);

// render_cylinder.c
double	get_distance_of_cylinder(t_cylinder *cylinder, t_ray ray);
size_t	get_color_of_cylinder(t_cylinder *cylinder, t_ray ray);

#endif