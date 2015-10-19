#include "fractol.h"

int		draw(t_env *env)
{
	printf("|||||%f/////\n", env->zoom);
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

int		mouse_hook(int	button, int x, int y, t_env *env)
{
	if (button == 6)
	{
		env->zoom += 20;
		
		draw(env);
	}
	if (button == 7)
	{
		env->zoom -= 20;
		draw(env);
	}
	if (button == 1)
	{
		zoom(env, x, y);
		draw(env);
	}
//	printf("button = %d \n", button);
//	printf("curr_pos x = %f cur_pos y  = %f \n", env->curr_pos->x, env->curr_pos->y);
	printf("%d || x :  %d  || y :%d || zoom : %f ||\n", button, x, y, env->zoom);
	return (0);
}

int		key(int key, t_env *env)
{
	if (key == 53)
		error(env,"User exit");
	else if (key == 78)
	{
		env->zoom = env->zoom + 5;
		printf("%f , %d \n", env->zoom, env->select);
		
	}
	printf("%d\n", key);
	return (0);
}
