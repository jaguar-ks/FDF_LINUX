/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:37 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/15 23:01:54 by faksouss         ###   ########.fr       */
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

t_pst	next_x_crd(t_fdf f, t_pst st, t_inf s, t_inf e)
{
	t_pst	en;
	int		z;

	z = e.z - s.z;
	en.x = st.x + f.i;
	en.y = st.y - f.j - (z * f.zs);
	en.cl = e.cl;
	return (en);
}

t_pst	next_y_crd(t_fdf f, t_pst st, t_inf s, t_inf e)
{
	t_pst	en;
	int		z;

	z = e.z - s.z;
	en.x = st.x + f.i;
	en.y = st.y + f.j - (z * f.zs);
	en.cl = e.cl;
	return (en);
}
