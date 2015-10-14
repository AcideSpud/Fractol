/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 10:31:47 by jrosamon          #+#    #+#             */
/*   Updated: 2015/10/14 11:38:31 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define ESCP 65307

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
}					t_env;

int					ft_init(t_env *env);
int					key(int key, t_env *env);
int					draw(t_env *env);
void				error(char *str);

#endif
