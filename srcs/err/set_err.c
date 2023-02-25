#include "../../incs/err.h"

t_bool	set_err(t_var *var, t_err err);

t_bool	set_err(t_var *var, t_err err)
{
	var->err = err;
	return (TRUE);
}
