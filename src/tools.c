#include "fractol.h"

void	set_scale(t_env *env)
{
	float	scale_x;
	float	scale_y;

	scale_x = env->lim->v2->x - env->lim->v1->x;
	scale_y = env->lim->v2->y - env->lim->v1->y;
	zoom(env, scale_x, scale_y);
}

void	set_discale(t_env *env)
{
	float	scale_x;
	float	scale_y;

	scale_x = (env->lim->v2->x - env->lim->v1->x) / 2;
	scale_y = (env->lim->v2->y - env->lim->v1->y) / 2;
	dezoom(env, scale_x, scale_y);
}

void	zoom(t_env *env, float scale_x, float scale_y)
{
	printf("%f, %f\n", env->curr_pos->x, env->curr_pos->y);
	if (env->select == 3 || env->select == 4 ||
			env->select == 5 || env->select == 6)
	{
		env->lim->v1->x =  env->curr_pos->x - (scale_x / 4);
		env->lim->v1->y =  env->curr_pos->y - (scale_y / 4);
		env->lim->v2->x =  env->curr_pos->x + (scale_x / 4);
		env->lim->v2->y =  env->curr_pos->y + (scale_y / 4);
		env->zoom += 50;
		env->lim->it_max += 10;
	}
}
void    dezoom(t_env *env, float scale_x, float scale_y)
{
	if (env->select == 3 || env->select == 4 ||
			env->select == 5 || env->select ==6)
	{
		env->lim->v1->x -= scale_x ;
		env->lim->v1->y -= scale_y;
		env->lim->v2->x += scale_x;
		env->lim->v2->y += scale_y;
		env->zoom -= 50;
		env->lim->it_max += 10;
	}
}

void	reset(t_env *env)
{
	if (env->select == 3)
		mandelbrot(env);
	else if (env->select == 4)
		init_julia(env);
	else if (env->select == 5)
		init_douady(env);
	else if (env->select == 6)
		init_burning(env);
}

void	it_plus(t_env *env)
{
	env->lim->it_max += 10;
}

void	it_moins(t_env *env)
{
	env->lim->it_max -= 50;
}
