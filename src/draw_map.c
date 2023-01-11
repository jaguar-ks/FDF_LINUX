/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:27:41 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 17:32:15 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	draw_map(t_fdf f)
{
	int		x;
	int		y;
	t_pst	p1;
	t_pst	p2;
	t_pst	p3;

	f.du = init_drawing_unit(f.dm);
	p1 = start_point(f.crd[0][0]);
	y = -1;
	while (++y < f.dm.ht - 1)
	{
		x = -1;
		p2 = next_x(f, p1);
		while (++x < f.dm.wt - 1)
		{
			p3 = next_y(f, p2);
			draw_line(f, p1, p2);
			draw_line(f, p2, p3);
			p2 = next_x(f, p2);
		}
		p1 = next_y(f, p1); 
	}
}
