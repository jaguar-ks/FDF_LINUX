/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 14:03:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_inf	*take_x_z_cl(char **y, int j)
{
	int		i;
	t_inf	*inf;
	char	**z;

	inf = (t_inf *)malloc(sizeof(t_inf) * mtx_len(y));
	i = -1;
	while (y[++i])
	{
		inf[i].x = i;
		inf[i].y = j;
		z = ft_split(y[i], ',');
		if (mtx_len(z) == 2)
		{
			inf[i].z = ft_atoi(z[0]);
			inf[i].cl = hex_to_dec(z[1]);
		}
		else
		{
			inf[i].z = ft_atoi(z[0]);
			inf[i].cl = 0xFFFFFF;
		}
		deallocate(z);
	}
	return (inf);
}

t_inf	**take_crd(char *map)
{
	t_inf	**inf;
	t_rd	rd;
	int		y;

	rd.y = ft_split(map, '\n');
	if (chck_map(rd.y) < 0)
		exit(error(-3));
	inf = (t_inf **)malloc(sizeof(t_inf *) * mtx_len(rd.y));
	y = -1;
	while (rd.y[++y])
	{
		rd.x = ft_split(rd.y[y], ' ');
		inf[y] = take_x_z_cl(rd.x, y);
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
