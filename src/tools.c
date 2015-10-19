#include "fractol.h"

void	zoom(t_env *env, float x, float y)
{
	if ((x > env->width / 2) && (y < env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x += 0.1;
		env->lim->v2->y -= 0.1;
		env->lim->it_max += 10;
	}

	if ((x < env->width / 2) && (y > env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x -= 0.1;
		env->lim->v2->y += 0.1;
		env->lim->it_max += 10;
	}
	if ((x < env->width / 2) && (y < env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x -= 0.1;
		env->lim->v2->y -= 0.1;
		env->lim->it_max += 10;
	}
	if ((x > env->width / 2) && (y > env->height / 2))
	{
		env->zoom += 50;
		env->lim->v1->x += 0.1;
		env->lim->v2->y += 0.1;
		env->lim->it_max += 10;
	}
}
