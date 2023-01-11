/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/10 21:03:21 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	mtx_len(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
		i++;
	return (i);
}

int	chck_opn(char *fl)
{
	int	fd;
	int	i;

	i = ft_strlen(fl);
	if (!ft_strncmp((fl + (i - 4)), ".fdf", 5))
	{
		fd = open(fl, O_RDWR);
		if (fd < 0)
			fd = -1;
	}
	else
		fd = -2;
	if (fd < 0)
		exit(error(fd));
	return (fd);
}

int	chck_map(char **map)
{
	int		*x;
	char	**ax;
	int		i;
	int		j;

	i = -1;
	x = (int *)malloc(mtx_len(map) * sizeof(int));
	if (!x)
		return (-1);
	while (map[++i])
	{
		ax = ft_split(map[i], ' ');
		x[i] = mtx_len(ax);
		deallocate(ax);
	}
	j = -1;
	while (++j < i)
		if (x[j] != x[i - 1])
			return (free(x), 0);
	return (free(x), 1);
}

t_inf	**read_map(char *mp, char **map)
{
	int			fd;
	int			i;
	int			j;
	t_rd		rd;
	t_inf		**inf;

	fd = chck_opn(mp);
	printf("|Done openning the file|\n");
	*map = gnl(fd);
	printf("|Done reading the file|\n");
	rd.y = ft_split(*map, '\n');
	printf("|Done taking the Y axis|\n");
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
