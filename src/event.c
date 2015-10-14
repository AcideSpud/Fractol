#include "fractol.h"

int		draw(t_env *env)
{
	(void)env;
	return (0);
}

int		key(int key, t_env *env)
{
	(void)env;
	if (key == 53)
		error("User exit");
	return (0);
}
