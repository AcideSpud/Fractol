#include "fractol.h"

int		draw(t_env *env)
{
	fill_img(env, 0);
	if (env->select == 1)
		cantor(env, 10, 20, env->width - 20);
	else if (env->select == 2)
		circle_fractal(env, 300, 300, 300.0);
	else if (env->select == 3)
		mandelbrot(env);
	else if (env->select == 4)
		julia(env);
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
