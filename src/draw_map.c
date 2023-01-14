/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:27:41 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/14 21:06:22 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	init_utils(t_fdf *f)
{
	f->du = init_drawing_unit(f->dm);
	f->zs = take_z_scale(*f);
	f->i = take_i(*f);
	f->j = take_j(*f);
}

void	draw_x_y(t_fdf f, t_pst st, t_pst x, t_pst y)
{
	draw_line(f, st, x);
	draw_line(f, st, y);
}

void	draw_map(t_fdf f)
{
	t_pst	st;
	t_pst	nt;
	t_draw	d;
	int		y;
	int		x;

	init_utils(&f);
	st = start_point(f.crd[0][0]);
	y = -1;
	while (++y < f.dm.ht - 1)
	{
		x = 0;
		d.x = next_x_crd(f, st, f.crd[y][x], f.crd[y][x + 1]);
		d.y = next_y_crd(f, st, f.crd[y][x], f.crd[y + 1][x]);
		nt = d.y;
		while (x < f.dm.wt - 1)
		{
			draw_x_y(f, st, d.x, d.y);
			x++;
			st = d.x;
			d.y = next_y_crd(f, st, f.crd[y][x], f.crd[y + 1][x]);
			d.x = next_x_crd(f, st, f.crd[y][x], f.crd[y][x + 1]);
		}
		st = nt;
	}
}
