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
		error("bad input !!!");
	}
}

int				init(t_env *env, char *arg)
{
	input_f(env, arg);
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
	draw(env);
	return (1);
}
