/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 18:07:37 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 17:17:15 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_param *p)
{
	mlx_clear_window(p->fdf.mlx, p->fdf.win);
	if (p->pro == 0)
	{
		p = ft_center_pr(p);
		ft_draw_z(p, 0, 0);
	}
	if (p->pro == 1)
	{
		p = ft_center_pr(p);
		ft_draw_y(p, 0, 0);
	}
	if (p->pro == 2)
	{
		p = ft_iso_pr(p);
		ft_draw_iso(p, 0, 0);
	}
}

int		key_press(int key, void *p)
{
	t_param *x;

	x = (t_param*)p;
	if (key == 53)
		exit(0);
	key == 6 ? x->pro = 0 : 0;
	key == 16 ? x->pro = 1 : 0;
	key == 34 ? x->pro = 2 : 0;
	key == 27 ? x->sizen *= 0.9 : 1;
	key == 24 ? x->sizen *= 1.1 : 1;
	key == 126 ? x->bias_y -= 10 : 0;
	key == 125 ? x->bias_y += 10 : 0;
	key == 123 ? x->bias_x -= 10 : 0;
	key == 124 ? x->bias_x += 10 : 0;
	ft_draw(x);
	return (0);
}

void	ft_make_win(t_point **map, t_param *p)
{
	t_ptr	fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, W_W, W_H, "fdf_42");
	p->fdf = fdf;
	p->map = map;
	mlx_key_hook(fdf.win, key_press, (void*)p);
	p = ft_center_pr(p);
	ft_draw_z(p, 0, 0);
	mlx_loop(fdf.mlx);
}
