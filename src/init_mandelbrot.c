#include "fractol.h"

void			mandelbrot(t_env *env)
{
	env->zoom = 300;
	env->lim->v1->x = -2.1;
	env->lim->v1->y = -1.2;
	env->lim->v2->x = 0.6;
	env->lim->v2->y = 1.2;
	env->lim->img_x = (env->lim->v2->x - env->lim->v1->x) * env->zoom;
	env->lim->img_y = (env->lim->v2->y - env->lim->v1->y) * env->zoom;
	env->lim->it_max = 50;
	env->lim->c_r = 0 / env->zoom + env->lim->v1->x;
	env->lim->c_i = 0 / env->zoom + env->lim->v1->y;
}
