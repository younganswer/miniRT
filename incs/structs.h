#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/libft/incs/libft.h"
# include "../libs/libvec/incs/vec3.h"
# include "../libs/libray/incs/libray.h"

# ifndef uint
#  define uint unsigned int
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
// # define SCREEN_WIDTH 1920
// # define SCREEN_HEIGHT 1080

typedef enum e_err
{
	NO_ERR = 0,
	GENERIC_ERR = 1,
	INVALID_FILENAME = 2,
	FAIL_TO_OPEN_FILE = 3,
	INVALID_IDENTIFIER = 4,
	INVALID_ARG = 5,
	INVALID_RANGE = 6,
	DUPLICATED_IDENTIFIER = 7,
}	t_err;

typedef enum e_x_event
{
	KEY_PRESSED = 2,
	KEY_DESTROY = 17,
}	t_x_event;

typedef struct s_alight
{
	double	ratio;
	t_vec3	color;
}	t_alight;

typedef struct s_camera
{
	t_ray	ray;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	higher_left_corner;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	origin;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef enum e_type
{
	LAMBERTIAN = 0,
	DIELECTRIC = 1,
}	t_type;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_vec3	color;
	t_type	type;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_vec3	color;
	t_type	type;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	normal;
	double	radius;
	double	height;
	t_vec3	color;
	t_type	type;
}	t_cylinder;

typedef enum e_shape
{
	SPHERE = 0,
	PLANE = 1,
	CYLINDER = 2,
}	t_shape;

typedef struct s_object
{
	void	*object;
	t_shape	shape;
}	t_object;

typedef struct s_hit
{
	t_object	*object;
	t_ray		ray;
	t_ray		normal;
}	t_hit;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_img;

typedef struct s_var
{
	t_mlx		*mlx;
	t_img		*img;
	t_alight	*alight;
	t_camera	*camera;
	t_list		*lights;
	t_list		*objects;
	t_err		err;
}	t_var;

#endif