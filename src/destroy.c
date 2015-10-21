#include "fractol.h"

int				free_env(t_env *env)
{
	free(env->color);
	free(env->curr_pos);
	free(env->lim->v1);
	free(env->lim->v2);
	free(env->lim);
	return (1);
}
