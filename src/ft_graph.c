/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:28:13 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 17:34:21 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_param *p, t_line *line)
{
	t_sub	delta;
	t_sub	sign;
	int		error[2];

	delta.x = abs(line->a.x - line->b.x);
	delta.y = abs(line->a.y - line->b.y);
	sign.x = line->a.x < line->b.x ? 1 : -1;
	sign.y = line->a.y < line->b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	while (line->a.x != line->b.x || line->a.y != line->b.y)
	{
		mlx_pixel_put(p->fdf.mlx, p->fdf.win, line->a.x, line->a.y, COLOR);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] = error[0] - delta.y;
			line->a.x = line->a.x + sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] = error[0] + delta.x;
			line->a.y = line->a.y + sign.y;
		}
	}
}
