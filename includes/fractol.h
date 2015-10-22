#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define PointerMotionMask	(1L<<6)

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_vertex
{
	float			x;
	float			y;
	float			z;
}					t_vertex;

typedef struct		s_lim
{
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			i;
	float			tmp;
	t_vertex		*v1;
	t_vertex		*v2;
	float			img_x;
	float			img_y;
	float			it_max;
}					t_lim;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*idata;
	int				width;
	int				height;
	int				ibits;
	int				isizeline;
	int				iendian;
	t_color			*color;
	t_vertex		*curr_pos;
	t_lim			*lim;
	int				select;
	float			x;
	float			zoom;
}					t_env;

void				it_plus(t_env *env);
void				it_moins(t_env *env);
void				mandel_algo(t_env* env);
int					init(t_env *env, char *arg);
int					free_env(t_env *env);
int					key(int key, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);
int					loop_hook(t_env *env);
int					mouse_move(int x, int y, t_env *env);
int					draw(t_env *env);
void				error(t_env *env, char *str);
void				fill_img(t_env *env, int color);
void				img_put_pixel(t_env *env, int x, int y, int color);
void				img_put_hline(t_env *env, t_vertex *v1, t_vertex *v2,
						int color);
void				img_put_vline(t_env *env, t_vertex *v1, t_vertex *v2,
						int color);
void				img_put_line(t_env *env, t_vertex *v1, t_vertex *v2,
						int color);
void				cantor(t_env *env, float x, float y, float len);
void				circle_fractal(t_env *env, float cx, float cy, float r);
void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				douady(t_env *env);
void				burning(t_env *env);
void				callmandel(t_env *env);
int					color_in_int(t_color *color);
void				modif_color(t_color *color);
void				choose_color(t_color *color, int r, int g, int b);
void				zoom(t_env *env);
void				dezoom(t_env *env);
void				reset(t_env *env);
void				init_julia(t_env *env);
void				init_douady(t_env *env);
void				init_burning(t_env *env);
#endif
