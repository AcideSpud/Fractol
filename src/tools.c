#include "fractol.h"

void	zoom(t_env *env)
{
	if (env->select == 3 || env->select == 4 ||
			env->select == 5 || env->select == 6)
	{
		env->lim->v1->x += env->curr_pos->x;
		env->lim->v1->y += env->curr_pos->y;
		env->lim->v2->x += env->curr_pos->x;
		env->lim->v2->y += env->curr_pos->y;
		env->zoom += 50;
		env->lim->it_max += 10;
	}
}

void	dezoom(t_env *env)
{
	if (env->select == 3 || env->select == 4 ||
			env->select == 5)
	{
		env->lim->v1->x += env->curr_pos->x;
		env->lim->v1->y += env->curr_pos->y;
		env->lim->v2->x += env->curr_pos->x;
		env->lim->v2->y += env->curr_pos->y;
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
	env->lim->it_max -= 10;
}
