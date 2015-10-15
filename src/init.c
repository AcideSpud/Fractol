#include "fractol.h"
/*
static	void		init_lim(t_lim *lim)
{
	lim->x_max = 0.6;
	lim->x_min = -2.1;
	lim->y_min = -1.2;
	lim->y_max = 1.2;
	lim->it_max = 50;
	lim->zoom = 100;
}

static	int			init_mandel(t_env *env)
{
	t_lim	lim;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (0);
	init_lim(&lim);
	env->height = (lim.x_max - lim.x_min) * lim.zoom;
	env->width = (lim.y_max - lim.y_min) * lim.zoom
	return (0);
}
*/
int			init_cantor(t_env * env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (0);
	env->color = (t_color*)malloc(sizeof(t_color));
	env->height = 800;
	env->width = 600;
	env->color->r = 200;
	env->color->g = 100;
	env->color->b = 50;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->idata = mlx_get_data_addr(env->img, &(env->ibits), &(env->isizeline),
			&(env->iendian));
	return (1);
}
/*
int			ft_init(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "cantor") == 0)
		init_cantor(env);
	else if (ft_strcmp(arg, "mandelbrot") == 0)
		init_mandel(env);
	else
		return (0);
	return (1);
}*/
