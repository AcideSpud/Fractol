#include "fractol.h"

int		draw(t_env *env)
{
	printf("|||||%f/////\n", env->zoom);
	fill_img(env, 0);
	printf("test\n");
	if (env->select == 1)
		cantor(env, 10, 20, env->width - 20);
	else if (env->select == 2)
		circle_fractal(env, 300, 300, 300.0);
	else if (env->select == 3)
		mandel_algo(env);
	else if (env->select == 4)
		julia(env);
	else if (env->select == 5)
		douady(env);
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
		env->curr_pos->x = ((float)x / (float)env->lim->img_x) * 2 - 1;
		env->curr_pos->y = ((float)y / (float)env->lim->img_y) * 2 - 1;
		printf("(%f ; %f)\n", env->curr_pos->x, env->curr_pos->y);
		zoom(env);
		draw(env);
	}
	if (button == 2)
	{
		env->curr_pos->x = ((float)x / (float)env->lim->img_x) * 2 - 1;
		env->curr_pos->x = ((float)y / (float)env->lim->img_y) * 2 - 1;
		dezoom(env);
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
	if (key == 69)
	{
		it_plus(env);
		draw(env);
	}
	if (key == 78)
	{
		it_moins(env);
		draw(env);
	}
	if (key == 49)
	{
		reset(env);
		draw(env);
	}
	printf("%d\n", key);
	return (0);
}
