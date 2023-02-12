#ifndef ERR_H
# define ERR_H

# include "structs.h"

// exit_with_err.c
int		exit_with_err(t_var *var);

// set_err.c
t_bool	set_err(t_var *var, t_err err);

#endif