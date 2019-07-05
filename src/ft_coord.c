/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:44:20 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 20:39:52 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_iso_v(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h - 1)
	{
		while (x < p->w)
		{
			line.a.x = ((p->map[y][x].x - p->map[y][x].y) * cos(0.523599) \
				* p->size + p->mar_w);
			line.a.y = (((p->map[y][x].x + p->map[y][x].y) * sin(0.523599) \
				- p->map[y][x].z) * p->size + p->mar_h);
			line.b.x = ((p->map[y + 1][x].x - p->map[y + 1][x].y) * \
				cos(0.523599) * p->size + p->mar_w);
			line.b.y = (((p->map[y + 1][x].x + p->map[y + 1][x].y) * \
				sin(0.523599) - p->map[y + 1][x].z) * p->size + p->mar_h);
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_draw_iso(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h)
	{
		while (x < p->w - 1)
		{
			line.a.x = ((p->map[y][x].x - p->map[y][x].y) * cos(0.523599) \
				* p->size + p->mar_w);
			line.a.y = (((p->map[y][x].x + p->map[y][x].y) * sin(0.523599) \
				- p->map[y][x].z) * p->size + p->mar_h);
			line.b.x = ((p->map[y][x + 1].x - p->map[y][x + 1].y) * \
				cos(0.523599) * p->size + p->mar_w);
			line.b.y = (((p->map[y][x + 1].x + p->map[y][x + 1].y) * \
				sin(0.523599) - p->map[y][x + 1].z) * p->size + p->mar_h);
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_iso_v(p, 0, 0);
}
