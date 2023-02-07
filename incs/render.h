#ifndef RENDER_H
# define RENDER_H

# include "structs.h"

// render.c
int	render(t_var *var);

// render_shape.c
t_bool	render_shape(t_var *var);

// render_sphere.c
t_bool	render_sphere(t_var *var, t_sphere *sphere);

#endif