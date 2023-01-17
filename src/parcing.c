/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/17 01:21:17 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	map_len(int fd, t_dmt *dm)
{
	int		y;
	int		x;
	char	*ln;
	char	**s;

	ln = gnl(fd);
	s = ft_split(ln, ' ');
	x = mtx_len(s);
	y = 0;
	while (1)
	{
		free(ln);
		deallocate(s);
		y++;
		ln = gnl(fd);
		if (!ln)
			break ;
		s = ft_split(ln, ' ');
		if (x != mtx_len(s))
			exit(error(-3));
	}
	dm->ht = y;
	dm->wt = x;
	close(fd);
}

t_inf	*take_x_z_cl(char **y, int j, t_fdf f)
{
	int		i;
	t_inf	*inf;
	char	**z;

	inf = (t_inf *)malloc(sizeof(t_inf) * f.dm.wt);
	if (!inf)
		exit(error(-4));
	i = -1;
	while (y[++i])
	{
		inf[i].x = i;
		inf[i].y = j;
		z = ft_split(y[i], ',');
		inf[i].z = ft_atoi(z[0]);
		if (mtx_len(z) == 2)
			inf[i].cl = hex_to_dec(z[1]);
		else
			inf[i].cl = 0xFFFFFF;
		deallocate(z);
	}
	return (deallocate(y), inf);
}

t_inf	**read_map(char *mp, t_fdf f)
{
	int		fd;
	int		i;
	char	*map;
	t_inf	**inf;

	fd = chck_opn(mp);
	inf = (t_inf **)malloc(sizeof(t_inf *) * f.dm.ht);
	if (!inf)
		exit(error(-4));
	i = -1;
	while (++i < f.dm.ht)
	{
		map = gnl(fd);
		inf[i] = take_x_z_cl(ft_split(map, ' '), i, f);
		free(map);
	}
	return (inf);
}
