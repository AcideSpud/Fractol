#include "fractol.h"

static	void	choose_input(void)
{
	ft_putstr("__INPUT__ :\n");
	ft_putstr("1 - cantor\n");
	ft_putstr("2 - circle\n");
	ft_putstr("3 - mandelbrot\n");
	ft_putstr("4 - julia\n");
}

static	void	input_f(t_env *env, char *arg)
{
	if (ft_strcmp(arg, "1") == 0)
		env->select = 1;
	else if (ft_strcmp(arg, "2") == 0)
		env->select = 2;
	else if (ft_strcmp(arg, "3") == 0)
		env->select = 3;
	else if (ft_strcmp(arg, "4") == 0)
		env->select = 4;
	else
	{
		choose_input();
		error(env, "bad input !!!");
	}
}

static	void	init_julia(t_env *env)
{
	env->lim->v1->x = -1;
	env->lim->v1->y = -1.2;
	env->lim->v2->x = 1;
	env->lim->v2->y = 1.2;
	env->lim->it_max = 150;
}

int				init(t_env *env, char *arg)
{
	input_f(env, arg);
	env->mlx = mlx_init();
	if (!env->mlx)
		return (0);
	env->color = (t_color*)malloc(sizeof(t_color));
	env->curr_pos = (t_vertex*)malloc(sizeof(t_vertex));
	env->lim = (t_lim*)malloc(sizeof(t_lim));
	env->lim->v1 = (t_vertex*)malloc(sizeof(t_lim));
	env->lim->v2 = (t_vertex*)malloc(sizeof(t_lim));
	init_julia(env);
	env->curr_pos->x = 0;
	env->curr_pos->y = 0;
	env->height = 700;
	env->width = 825;
	env->color->r = 200;
	env->color->g = 100;
	env->color->b = 50;
	env->zoom = 300;
	mandelbrot(env);
	env->win = mlx_new_window(env->mlx, env->lim->img_x, env->lim->img_y, "fractol");
	env->img = mlx_new_image(env->mlx, env->lim->img_x, env->lim->img_y);
	env->idata = mlx_get_data_addr(env->img, &(env->ibits), &(env->isizeline),
			&(env->iendian));
	draw(env);
	return (1);
}

int				free_env(t_env *env)
{
	free(env->color);
	free(env->curr_pos);
	free(env->lim->v1);
	free(env->lim->v2);
	free(env->lim);
	return (1);
}
