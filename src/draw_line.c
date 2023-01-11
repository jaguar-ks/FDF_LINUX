/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:53:04 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 17:14:46 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	draw_line(t_fdf f, t_pst st, t_pst en)
{
	double	dx;
	double	dy;
	double	inx;
	double	iny;
	int		i;
	int		j;

	dx = en.x - st.x;
	dy = en.y - st.y;
	if (fabs(dx) > fabs(dy))
		i = fabs(dx);
	else
		i = fabs(dy);
	inx = dx / i;
	iny = dy / i;
	j = -1;
	while (++j <= i)
	{
		if (j >= i / 2)
			st.cl = en.cl;
		mlx_pixel_put(f.mlx, f.win, (int)(st.x + 0.5), (int)(st.y + 0.5), st.cl);
		st.x += inx;
		st.y += iny;
	}
}
