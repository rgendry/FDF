/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:48:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 20:17:13 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"

# define W_W 2560
# define W_H 1300
# define COLOR 0x0886fc

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

typedef struct	s_line
{
	t_dot		a;
	t_dot		b;
}				t_line;

typedef struct	s_sub
{
	double		x;
	double		y;
}				t_sub;

typedef struct	s_ptr
{
	void		*mlx;
	void		*win;
}				t_ptr;

typedef struct	s_param
{
	t_ptr		fdf;
	t_point		**map;
	int			z0;
	int			ze;
	int			w;
	int			h;
	double		size;
	double		sizen;
	int			mar_w;
	int			mar_h;
	int			mar_z;
	int			pro;
	int			bias_x;
	int			bias_y;
}				t_param;

t_point			**ft_validation(char *file, t_param *p);
void			ft_make_win(t_point **map, t_param *p);
void			ft_drawline(t_param *p, t_line *line);
void			ft_draw(t_param *p);
void			ft_draw_z(t_param *p, int x, int y);
void			ft_draw_y(t_param *p, int x, int y);
void			ft_draw_iso(t_param *p, int x, int y);
t_param			ft_init();
t_point			**ft_puterr();
int				ft_puterr1();
t_param			*ft_center_pr(t_param *p);
t_param			*ft_iso_pr(t_param *p);

#endif
