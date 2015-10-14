#include "fractol.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_env	env;
	if(!ft_init(&env))
		return (0);
	mlx_loop(env.mlx);

	return (0);
}


