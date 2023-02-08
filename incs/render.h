#ifndef RENDER_H
# define RENDER_H

# include "structs.h"

// render.c
int	render(t_var *var);

// render_sphere.c
double	hit_sphere(t_sphere *sphere, t_ray ray);
size_t	get_color_of_sphere(t_sphere *sphere, t_ray ray, double t);

// render_plane.c
double	hit_plane(t_plane *plane, t_ray ray);
size_t	get_color_of_plane(t_plane *plane, t_ray ray, double t);

// render_cylinder.c
double	hit_cylinder(t_cylinder *cylinder, t_ray ray);
size_t	get_color_of_cylinder(t_cylinder *cylinder, t_ray ray, double t);

#endif