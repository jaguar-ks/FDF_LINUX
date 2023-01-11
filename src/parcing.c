/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 12:59:23 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_inf	**take_crd(char *map)
{
	t_inf	**inf;
	t_rd	rd;
	int		y;
	int		x;

	rd.y = ft_split(map, '\n');
	inf = (t_inf **)malloc(sizeof(t_inf *) * mtx_len(rd.y));
	y = -1;
	while (rd.y[++y])
	{
		rd.x = ft_split(rd.y[y], ' ');
		inf[y] = (t_inf *)malloc(sizeof(t_inf) * mtx_len(rd.x));
		x = -1;
		while (rd.x[++x])
		{
			inf[y][x].x = x;
			inf[y][x].y = y;
			rd.z = ft_split(rd.x[x], ',');
			if (mtx_len(rd.z) == 2)
			{
				inf[y][x].z = ft_atoi(rd.z[0]);
				inf[y][x].cl = hex_to_dec(rd.z[1]);
			}
			else
			{
				inf[y][x].z = ft_atoi(rd.z[0]);
				inf[y][x].cl = 0xFFFFFF;
			}
			deallocate(rd.z);
		}
		deallocate(rd.x);
	}
	return (deallocate(rd.y), inf);
}

t_inf	**read_map(char *mp, char **map)
{
	int			fd;
	t_inf		**inf;

	fd = chck_opn(mp);
	*map = gnl(fd);
	inf = take_crd(*map);
	return (inf);
}
