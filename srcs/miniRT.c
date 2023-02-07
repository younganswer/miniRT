#include "../libs/libft/incs/libft.h"
#include "../incs/structs.h"
#include "../incs/parse.h"
#include "../incs/err.h"

static t_bool	init_var(t_var *var, char *file);

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
		ft_exit_with_error("Usage: ./miniRT /path_to_rt/scene.rt", INVALID_ARG);
	if (init_var(&var, argv[1]) == FALSE)
		ft_exit_with_error("Error: Fail to init var", GENERIC_ERR);
	return (0);
}

static t_bool	init_var(t_var *var, char *file)
{
	var = ft_calloc(sizeof(t_var), 1, "Error: Fail to init var");
	return (parse(var, file));
}
