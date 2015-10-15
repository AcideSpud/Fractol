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
# define ESCP 65307

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

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
}					t_env;

typedef struct		s_lim
{
	int				x_max;
	int				x_min;
	int				y_min;
	int				y_max;
	int				it_max;
	int				zoom;
}					t_lim;

typedef struct		s_vertex
{
	float			x;
	float			y;
	float			z;
}					t_vertex;

int					ft_init(t_env *env, char *arg);
int					init_cantor(t_env *env);
int					key(int key, t_env *env);
int					draw(t_env *env);
void				error(char *str);
void				fill_img(t_env *env, int color);
void				img_put_pixel(t_env *env, int x, int y, int color);
void				img_put_hline(t_env *env, t_vertex *v1, t_vertex *v2, int color);
void				img_put_vline(t_env *env, t_vertex *v1, t_vertex *v2, int color);
void				img_put_line(t_env *env, t_vertex *v1, t_vertex *v2, int color);
void				cantor(t_env *env, float x, float y, float len);
void				draw_ellipse(t_env *env, float cx, float cy, float radius);
void				circle_fractal(t_env *env, float cx, float cy, float r);
void				mandelbrot(t_env *env);
void				julia(t_env *env);
void				callmandel(t_env *env);
int					color_in_int(t_color *color);
void				modif_color(t_color *color);
void				choose_color(t_color *color, int r, int g, int b);

#endif