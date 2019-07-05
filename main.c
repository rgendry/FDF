/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:51:42 by rgendry           #+#    #+#             */
/*   Updated: 2019/07/02 20:16:22 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point **map;
	t_param p;

	if (argc != 2)
		return (ft_puterr1());
	p = ft_init();
	if (!(map = ft_validation(argv[1], &p)))
		return (0);
	ft_make_win(map, &p);
	return (0);
}
