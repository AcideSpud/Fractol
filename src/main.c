#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		error("no arg");
	if (!ft_init(&env, av[1]))
		return (0);
	mlx_expose_hook(env.win, draw, &env);
	mlx_key_hook(env.win, key, &env);
	mlx_loop(env.mlx);
	return (0);
}
