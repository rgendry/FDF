/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:54:40 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 21:02:02 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**ft_puterr(void)
{
	ft_putstr("Error: invalid file\n");
	return (NULL);
}

int			ft_puterr1(void)
{
	ft_putstr("Error: wrong amount of arguments\n");
	return (0);
}

t_param		*ft_center_pr(t_param *p)
{
	if ((2000 / p->w) > (1000 / p->h))
		p->size = 1000 / p->h;
	else
		p->size = 2000 / p->w;
	if ((abs(p->z0) + abs(p->ze)) * p->size > W_H)
		p->size = 1000 / (abs(p->z0) + abs(p->ze));
	p->size = p->size * p->sizen;
	p->mar_w = (W_W - p->size * p->w) / 2 + p->bias_x;
	p->mar_h = (W_H - p->size * p->h) / 2 + p->bias_y;
	p->mar_z = (W_H - p->size * (abs(p->z0) - abs(p->ze))) / 2 + p->bias_y;
	return (p);
}

t_param		*ft_iso_pr(t_param *p)
{
	int m;

	if (p->h > p->w)
		m = p->h;
	else
		m = p->w;
	p->size = 1100 / (abs(p->z0) + abs(p->ze) + m);
	if ((2000 / (p->h + p->w)) < p->size)
		p->size = 2000 / (p->h + p->w);
	p->size = p->size * p->sizen;
	p->mar_w = (W_W - (p->size * p->w / 2)) / 2 + p->bias_x;
	p->mar_h = (W_H - sqrt(pow(p->h * p->size, 2) + pow((abs(p->z0) - \
		abs(p->ze) + m / 2) * p->size, 2))) / 2 + p->bias_y;
	p->mar_z = (W_H - p->size * (abs(p->z0) - abs(p->ze))) / 2 + p->bias_y;
	if (p->mar_z < p->mar_h)
		p->mar_h = p->mar_z;
	return (p);
}

t_param		ft_init(void)
{
	t_param p;

	p.fdf.mlx = NULL;
	p.fdf.win = NULL;
	p.map = NULL;
	p.z0 = 2147483647;
	p.ze = -2147483648;
	p.w = 0;
	p.h = 0;
	p.mar_h = 0;
	p.mar_w = 0;
	p.mar_z = 0;
	p.size = 10;
	p.sizen = 1;
	p.bias_x = 0;
	p.bias_y = 0;
	return (p);
}
