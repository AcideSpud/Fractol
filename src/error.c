#include "fractol.h"

void	error(t_env *env, char *str)
{
	if (env)
		free_env(env);
	ft_putendl(str);
	exit(1);
}
