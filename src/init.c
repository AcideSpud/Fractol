#include "fractol.h"

static	void	choose_input(void)
{
	ft_putstr("__INPUT__ :\n");
	ft_putstr("1 - cantor\n");
	ft_putstr("2 - circle\n");
	ft_putstr("3 - mandelbrot\n");
	ft_putstr("4 - julia\n");
	ft_putstr("5 - douady\n");
	ft_putstr("6 - burning\n");
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
	else if (ft_strcmp(arg, "5") == 0)
		env->select = 5;
	else if (ft_strcmp(arg, "6") == 0)
		env->select = 6;
	else
	{
		choose_input();
		error(env, "bad input !!!");
	}
}

static	void	malloc_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		error(env, "mlx_init() fail");
	if (!(env->color = (t_color*)malloc(sizeof(t_color))))
		error(env, "malloc color failed");
	env->curr_pos = (t_vertex*)malloc(sizeof(t_vertex));
	env->lim = (t_lim*)malloc(sizeof(t_lim));
	env->lim->v1 = (t_vertex*)malloc(sizeof(t_lim));
	env->lim->v2 = (t_vertex*)malloc(sizeof(t_lim));
}

static	void	env_init(t_env *env)
{
	env->curr_pos->x = 0;
	env->curr_pos->y = 0;
	env->lim->img_y = 800;
	env->lim->img_x = 600;
	env->color->r = 200;
	env->color->g = 100;
	env->color->b = 50;
}

int				init(t_env *env, char *arg)
{
	malloc_env(env);
	input_f(env, arg);
	env_init(env);
	if (env->select == 4)
		init_julia(env);
	else if (env->select == 3)
		mandelbrot(env);
	else if (env->select == 5)
		init_douady(env);
	else if (env->select == 6)
		init_burning(env);
	env->win = mlx_new_window(env->mlx, env->lim->img_x,
			env->lim->img_y, "fractol");
	env->img = mlx_new_image(env->mlx, env->lim->img_x, env->lim->img_y);
	env->idata = mlx_get_data_addr(env->img, &(env->ibits), &(env->isizeline),
			&(env->iendian));
	draw(env);
	return (1);
}
