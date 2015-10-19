#include "fractol.h"

void	zoom(t_env *env, float x, float y)
{
	(void)x;
	(void)y;
	if (env->select == 3)
	{
		env->lim->v1->x += env->curr_pos->x;
		env->lim->v1->y += env->curr_pos->y;
		env->lim->v2->x += 0.6 + env->curr_pos->x;
		env->lim->v2->y += 1.2 + env->curr_pos->y;
		env->zoom += 100;
		//env->lim->v1->x += 0.1;
		//env->lim->v2->y -= 0.1;
		env->lim->it_max += 50;
	}
/*	if ((x < env->width / 2) && (y > env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x -= 0.1;
		env->lim->v2->y += 0.1;
		env->lim->it_max += 50;
	}
	if ((x < env->width / 2) && (y < env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x -= 0.1;
		env->lim->v2->y -= 0.1;
		env->lim->it_max += 50;
	}
	if ((x > env->width / 2) && (y > env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x += 0.1;
		env->lim->v2->y += 0.1;
		env->lim->it_max += 50;
	}
	*/
}

