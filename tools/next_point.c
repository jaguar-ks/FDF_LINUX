/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:37 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/13 02:45:00 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_pst	next_x(t_fdf f, t_pst st)
{
	t_pst	en;
	int		agl;

	agl = -6;
	en.x = st.x + (int)(f.du * cos(M_PI / agl));
	en.y = st.y + (int)(f.du * sin(M_PI / agl));
	en.cl = st.cl;
	return (en);
}

t_pst	next_y(t_fdf f, t_pst st)
{
	t_pst	en;
	int		agl;

	agl = 6;
	en.x = st.x + (int)(f.du * cos(M_PI / agl));
	en.y = st.y + (int)(f.du * sin(M_PI / agl));
	en.cl = st.cl;
	return (en);
}
