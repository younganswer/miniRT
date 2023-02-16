#ifndef VEC3_H
# define VEC3_H

# ifndef uint
#  define uint unsigned int
# endif

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

// vec3_four_fundamental_arithmetic_operations.c
t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec, double scalar);
t_vec3	vec3_div(t_vec3 vec, double scalar);

// vec3_products.c
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_matrix(t_vec3 vec1, t_vec3 vec2);

// vec3_utils.c
t_vec3	vec3_reverse(t_vec3 vec);
t_vec3	vec3_unit(t_vec3 vec);
double	vec3_length(t_vec3 vec);
double	vec3_length_squared(t_vec3 vec);

#endif