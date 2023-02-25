#include "../libs/libft/incs/libft.h"
#include "../libs/libmlx/incs/mlx.h"
#include "../incs/structs.h"
#include "../incs/parse.h"
#include "../incs/render.h"
#include "../incs/err.h"
#include "../incs/event.h"

static t_bool	init_var(t_var *var, char *file);
static t_bool	check_filename(t_var *var, char *file);
static t_bool	init_mlx(t_var *var);
static t_bool	init_img(t_var *var);

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc != 2)
		ft_exit_with_error("Usage: ./miniRT /path_to_rt/scene.rt", INVALID_ARG);
	var = ft_calloc(sizeof(t_var), 1, "Error: Fail to init var");
	if (init_var(var, argv[1]) == FALSE)
		exit_with_err(var);
	if (render(var) == FALSE)
		exit_with_err(var);
	mlx_hook(var->mlx->window, KEY_DESTROY, 0, exit_with_err, var);
	mlx_hook(var->mlx->window, KEY_PRESSED, 0, key_pressed, var);
	mlx_loop(var->mlx->mlx);
	return (0);
}

static t_bool	init_var(t_var *var, char *file)
{
	return (
		check_filename(var, file) && \
		parse(var, file) && \
		init_mlx(var) && \
		init_img(var)
	);
}

static t_bool	check_filename(t_var *var, char *file)
{
	const size_t	file_len = ft_strlen(file);
	char			*ext;

	if (file_len < 3)
		return (set_err(var, INVALID_FILENAME) && FALSE);
	ext = file + file_len - 3;
	return (
		ft_strncmp(ext, ".rt", 3) == 0 || \
		(set_err(var, INVALID_FILENAME) && FALSE)
	);
}

static t_bool	init_mlx(t_var *var)
{
	var->mlx = ft_calloc(sizeof(t_mlx), 1, "Error: Fail to init mlx");
	var->mlx->mlx = mlx_init();
	if (var->mlx->mlx == NULL)
		return (set_err(var, GENERIC_ERR) && FALSE);
	var->mlx->window = mlx_new_window(
			var->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "miniRT");
	if (var->mlx->window == NULL)
		return (set_err(var, GENERIC_ERR) && FALSE);
	return (TRUE);
}

static t_bool	init_img(t_var *var)
{
	var->img = ft_calloc(sizeof(t_img), 1, "Error: Fail to init img");
	var->img->img = mlx_new_image(var->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (var->img->img == NULL)
		return (set_err(var, GENERIC_ERR) && FALSE);
	var->img->addr = (uint *) mlx_get_data_addr(
			var->img->img, &var->img->bits_per_pixel,
			&var->img->size_line, &var->img->endian
			);
	if (var->img->addr == NULL)
		return (set_err(var, GENERIC_ERR) && FALSE);
	return (TRUE);
}
