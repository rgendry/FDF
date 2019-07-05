/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:23:09 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 17:25:18 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check(char *line)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') && (i == 0 || line[i - 1] == ' '
					|| line[i - 1] == '-'))
			x++;
		i++;
	}
	return (x);
}

t_point	**ft_create(int sizex, int sizey)
{
	int		i;
	t_point	**map;

	i = 0;
	map = (t_point**)malloc(sizeof(t_point*) * sizey);
	while (i < sizey)
	{
		map[i] = (t_point*)malloc(sizeof(t_point) * sizex);
		i++;
	}
	return (map);
}

t_point	**ft_fill(char *line, t_param *p, int y, t_point **map)
{
	int x;

	x = 0;
	while (x < p->w)
	{
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].z = ft_atoi(line);
		if (p->z0 > map[y][x].z)
			p->z0 = map[y][x].z;
		if (p->ze < map[y][x].z)
			p->ze = map[y][x].z;
		while (*line && (*line == '-' || (*line >= '0' && *line <= '9')))
			line++;
		if (*line == ',')
			line = line + 8;
		while (*line && *line == ' ')
			line++;
		x++;
	}
	return (map);
}

t_point	**ft_read(char *file, t_param *p, t_point **map)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) && y < p->h)
	{
		ft_fill(line, p, y, map);
		y++;
	}
	if (y == p->h)
		return (map);
	return (NULL);
}

t_point	**ft_validation(char *file, t_param *p)
{
	int		old_x;
	int		fd;
	char	*line;

	old_x = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_puterr());
	while (get_next_line(fd, &line))
	{
		if ((p->w = ft_check(line)) == 0 || p->w < 2)
			return (ft_puterr());
		if (old_x != 0 && old_x != p->w)
			return (ft_puterr());
		old_x = p->w;
		p->h++;
	}
	close(fd);
	if (p->h < 2)
		return (ft_puterr());
	return (ft_read(file, p, ft_create(p->w, p->h)));
}
