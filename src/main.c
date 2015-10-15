#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	env;

	(void)ac;
	(void)av;
	if (ac < 2)
		error("no arg");
	if (!init_cantor(&env))
		return (0);
	mlx_expose_hook(env.win, draw, &env);
	mlx_key_hook(env.win, key, &env);
	mlx_loop(env.mlx);
	return (0);
}
