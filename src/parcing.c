/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 12:24:59 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_inf	**read_map(char *mp, char **map)
{
	int			fd;
	int			i;
	int			j;
	t_rd		rd;
	t_inf		**inf;

	fd = chck_opn(mp);
	*map = gnl(fd);
	rd.y = ft_split(*map, '\n');
	inf = (t_inf **)malloc(sizeof(t_inf *) * mtx_len(rd.y));
	i = -1;
	while (rd.y[++i])
	{
		rd.x = ft_split(rd.y[i], ' ');
		inf[i] = (t_inf *)malloc(sizeof(t_inf) * mtx_len(rd.x));
		j = -1;
		while (rd.x[++j])
		{
			inf[i][j].x = j;
			inf[i][j].y = i;
			rd.z = ft_split(rd.x[j], ',');
			if (mtx_len(rd.z) == 2)
			{
				inf[i][j].z = ft_atoi(rd.z[0]);
				inf[i][j].cl = hex_to_dec(rd.z[1]);
			}
			else
			{
				inf[i][j].z = ft_atoi(rd.z[0]);
				inf[i][j].cl = 0xFFFFFF;
			}
			deallocate(rd.z);
		}
		deallocate(rd.x);
	}
	return (deallocate(rd.y), inf);
}
