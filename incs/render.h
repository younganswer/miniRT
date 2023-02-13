#ifndef RENDER_H
# define RENDER_H

# include "structs.h"

// render.c
int	render(t_var *var);

// render_sphere.c
double			get_distance_to_sphere(void *object, t_ray ray);
unsigned int	get_color_to_sphere(void *object, t_ray ray);

// render_plane.c
double			get_distance_to_plane(void *object, t_ray ray);
unsigned int	get_color_to_plane(void *object, t_ray ray);

// render_cylinder.c
double			get_distance_to_cylinder(void *object, t_ray ray);
unsigned int	get_color_to_cylinder(void *object, t_ray ray);

#endif