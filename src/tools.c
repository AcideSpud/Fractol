#include "fractol.h"

void	zoom(t_env *env)
{
	if (env->select == 3 || env->select == 4)
	{
		env->lim->v1->x += env->curr_pos->x;
		env->lim->v1->y += env->curr_pos->y;
		env->lim->v2->x += env->curr_pos->x;
		env->lim->v2->y += env->curr_pos->y;
		env->zoom += 100;
		env->lim->it_max += 50;
	}
}
void    dezoom(t_env *env)
{
	if (env->select == 3 || env->select == 4)
	{
		env->lim->v1->x += env->curr_pos->x;
		env->lim->v1->y += env->curr_pos->y;
		env->lim->v2->x += env->curr_pos->x;
		env->lim->v2->y += env->curr_pos->y;
		env->zoom -= 100;
		env->lim->it_max += 50;
	}
}

void	reset(t_env *env)
{
	if (env->select == 3)
		mandelbrot(env);
	else if (env->select == 4)
		init_julia(env);
}

void	it_plus(t_env *env)
{
	env->lim->it_max += 10;
}

void	it_moins(t_env *env)
{
	env->lim->it_max -= 10;
}
