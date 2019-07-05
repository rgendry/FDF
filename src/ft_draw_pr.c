/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:00:25 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 14:31:13 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_z_v(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h - 1)
	{
		while (x < p->w)
		{
			line.a.x = p->map[y][x].x * p->size + p->mar_w;
			line.a.y = p->map[y][x].y * p->size + p->mar_h;
			line.b.x = p->map[y + 1][x].x * p->size + p->mar_w;
			line.b.y = p->map[y + 1][x].y * p->size + p->mar_h;
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_draw_z(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h)
	{
		while (x < p->w - 1)
		{
			line.a.x = p->map[y][x].x * p->size + p->mar_w;
			line.a.y = p->map[y][x].y * p->size + p->mar_h;
			line.b.x = p->map[y][x + 1].x * p->size + p->mar_w;
			line.b.y = p->map[y][x + 1].y * p->size + p->mar_h;
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_z_v(p, 0, 0);
}

void	ft_draw_y_v(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h - 1)
	{
		while (x < p->w)
		{
			line.a.x = p->map[y][x].x * p->size + p->mar_w;
			line.a.y = -p->map[y][x].z * p->size + p->mar_z;
			line.b.x = p->map[y + 1][x].x * p->size + p->mar_w;
			line.b.y = -p->map[y + 1][x].z * p->size + p->mar_z;
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_draw_y(t_param *p, int x, int y)
{
	t_line	line;

	while (y < p->h)
	{
		while (x < p->w - 1)
		{
			line.a.x = p->map[y][x].x * p->size + p->mar_w;
			line.a.y = -p->map[y][x].z * p->size + p->mar_z;
			line.b.x = p->map[y][x + 1].x * p->size + p->mar_w;
			line.b.y = -p->map[y][x + 1].z * p->size + p->mar_z;
			ft_drawline(p, &line);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_y_v(p, 0, 0);
}
