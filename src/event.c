#include "fractol.h"

int		draw(t_env *env)
{
	fill_img(env, 0);
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
	else if (env->select == 6)
		burning(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *env)
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
		env->curr_pos->x = ((float)x / (float)env->lim->img_x)
			* (env->lim->v2->x - env->lim->v1->x) + env->lim->v1->x;
		env->curr_pos->y = ((float)y / (float)env->lim->img_y)
			* (env->lim->v2->y - env->lim->v1->y) + env->lim->v1->y;
		set_scale(env);
		//zoom(env);
		draw(env);
	}
	if (button == 2)
	{
		env->curr_pos->x = ((float)x / (float)env->lim->img_x)
			* (env->lim->v2->x - env->lim->v1->x) + env->lim->v1->x;
		env->curr_pos->y = ((float)y / (float)env->lim->img_y)
			* (env->lim->v2->x - env->lim->v1->x) + env->lim->v1->x;
		set_discale(env);
		//dezoom(env);
		draw(env);
	}
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{
	if (env->select == 4)
	{
		env->curr_pos->x = ((float)x / (float)env->lim->img_x) * 2 - 1;
		env->curr_pos->y = ((float)y / (float)env->lim->img_y) * 2 - 1;
		if (x % 5 == 0 || y % 5 == 0)
			draw(env);
	}
	return (0);
}

int		loop_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_string_put(env->mlx, env->win, 10, 20, 0xFFFFFF, "Space Bar = Reset");
	mlx_string_put(env->mlx, env->win, 10, 40, 0xFFFFFF, "+ = iteration++");
	mlx_string_put(env->mlx, env->win, 10, 60, 0xFFFFFF, "- = iteration--");
	return (0);
}

int		key(int key, t_env *env)
{
	if (key == 53)
		error(env, "User exit");
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
	return (0);
}
