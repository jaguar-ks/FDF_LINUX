/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:27:41 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/13 03:07:56 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	draw_map(t_fdf f)
{
	t_pst	st;
	t_pst	nt;
	t_pst	j;
	t_pst	i;
	int		y;
	int		x;

	f.du = init_drawing_unit(f.dm);
	f.zs = take_z_scale(f);
	f.i = take_i(f);
	f.j = take_j(f);
	st = start_point(f.crd[0][0]);
	i = st;
	j = st;
	y = -1;
	while(++y < f.dm.ht - 1)
	{
		x = -1;
		i.x += f.i;
		j.x += f.i;
		i.y -= f.j;
		j.y += f.j;
		st.cl = f.crd[y][x + 1].cl;
		i.cl = f.crd[y][x + 2].cl;
		j.cl = f.crd[y + 1][x + 1].cl;
		nt = j;
		while (++x < f.dm.wt - 1)
		{
			if (x == 0)
			{
				draw_line(f, st, i);
				draw_line(f, st, j);
			}
			else
			{
				st = i;
				i.x += f.i;
				j.x += f.i;
				if (f.crd[y][x].z == f.crd[y][x + 1].z && f.crd[y][x].z != f.crd[y + 1][x].z)
				{
					i.y -= f.j;
					j.y = (j.y + f.j) - (f.crd[y][x + 1].z * f.zs);
				}
				else if (f.crd[y][x].z == f.crd[y + 1][x].z && f.crd[y][x].z != f.crd[y][x + 1].z)
				{
					j.y += f.j;
					i.y = (i.y - f.j) + (f.crd[y][x].z * f.zs);
				}
				else if (f.crd[y][x].z != f.crd[y][x + 1].z && f.crd[y][x].z != f.crd[y + 1][x].z)
				{
					j.y = (j.y + f.j) - (f.crd[y][x].z * f.zs);
					i.y = (i.y - f.j) + (f.crd[y][x].z * f.zs);
				}
				else
				{
					i.y -= f.j;
					j.y += f.j;
				}
				i.cl = f.crd[y][x + 2].cl;
				j.cl = f.crd[y + 1][x + 1].cl;
				draw_line(f, st, i);
				draw_line(f, st, j);
			}
		}
		st = nt;
	}
}
