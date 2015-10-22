#include "Fractol.h"

static void		brot_algo(t_env *env, int xx, int yy)
{
	while (((env->lim->z_r * env->lim->z_r) + (env->lim->z_i * env->lim->z_i))
			< 4 && (env->lim->i < env->lim->it_max))
	{
		env->lim->tmp = env->lim->z_r;
		env->lim->z_r = env->lim->z_r * env->lim->z_r
			- env->lim->z_i * env->lim->z_i + env->lim->c_r;
		env->lim->z_i = 2 * env->lim->z_i * env->lim->tmp + env->lim->c_i;
		env->lim->i++;
	}
	if (env->lim->i == env->lim->it_max)
	{
		choose_color(env->color, (env->lim->i * 10 / env->lim->it_max), 0, 0);
		img_put_pixel(env, xx, yy, color_in_int(env->color));
	}
	else
	{
		choose_color(env->color, 0, (env->lim->i * 255 * env->lim->it_max),
				(env->lim->i * 255 * env->lim->it_max));
		img_put_pixel(env, xx, yy, color_in_int(env->color));
	}
}

void			mandel_algo(t_env *env)
{
	int		xx;
	int		yy;

	xx = 0;
	while (xx < env->lim->img_x)
	{
		yy = 0;
		while (yy < env->lim->img_y)
		{
				env->lim->c_r =  (float)xx / env->lim->img_x * (env->lim->v2->x - env->lim->v1->x) + env->lim->v1->x;
				env->lim->c_i =  ((float)yy / env->lim->img_y * (env->lim->v2->y - env->lim->v1->y) + env->lim->v1->y);
			env->lim->z_r = 0;
			env->lim->z_i = 0;
			env->lim->i = 0;
			brot_algo(env, xx, yy);
			yy++;
		}
		xx++;
	}
}
