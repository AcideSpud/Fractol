#include "fractol.h"

int		draw(t_env *env)
{
	fill_img(env, 0);
	cantor(env, 10, 20, env->width - 20);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		key(int key, t_env *env)
{
	(void)env;
	if (key == 53)
		error("User exit");
	return (0);
}
