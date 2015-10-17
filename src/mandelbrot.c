#include "Fractol.h"

static void		brot_algo(t_env *env, t_lim *lim, int xx, int yy)
{
	while (((lim->z_r * lim->z_r) + (lim->z_i * lim->z_i)) < 4
			&& (lim->i < lim->it_max))
	{
		lim->tmp = lim->z_r;
		lim->z_r = lim->z_r * lim->z_r - lim->z_i * lim->z_i + lim->c_r;
		lim->z_i = 2 * lim->z_i * lim->tmp + lim->c_i;
		lim->i++;
	}
	if (lim->i == lim->it_max)
	{
		choose_color(env->color, 0, 0, 0);
		img_put_pixel(env, xx, yy, color_in_int(env->color));
	}
	else
	{
		choose_color(env->color, 0, (lim->i * 255 / lim->it_max),
				(lim->i * 255 / lim->it_max));
		img_put_pixel(env, xx, yy, color_in_int(env->color));
	}
}

static void		mandel_algo(t_env *env, t_lim *lim)
{
	int		xx;
	int		yy;

	xx = 0;
	while (xx < lim->img_x)
	{
		yy = 0;
		while (yy < lim->img_y)
		{
			lim->c_r = xx / env->zoom + lim->v1->x;
			lim->c_i = yy / env->zoom + lim->v1->y;
			lim->z_r = 0;
			lim->z_i = 0;
			lim->i = 0;
			brot_algo(env, lim, xx, yy);
			yy++;
		}
		xx++;
	}
}

void			mandelbrot(t_env *env)
{
	t_lim	lim;

	lim.v1 = (t_vertex*)malloc(sizeof(t_vertex));
	lim.v2 = (t_vertex*)malloc(sizeof(t_vertex));
	lim.v1->x = -2.1;
	lim.v1->y = -1.2;
	lim.v2->x = 0.6;
	lim.v2->y = 1.2;
	lim.img_x = (lim.v2->x - lim.v1->x) * env->zoom;
	lim.img_y = (lim.v2->y - lim.v1->y) * env->zoom;
	lim.it_max = 50;
	mandel_algo(env, &lim);
}
