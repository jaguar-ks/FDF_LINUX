/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:37 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:22 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_pst	next_x(t_fdf f, t_pst st)
{
	t_pst	en;
	int		agl;

	agl = -30;
	en.x = st.x + (int)(f.du * cos(agl * M_PI / 180));
	en.y = st.y + (int)(f.du * sin(agl * M_PI / 180));
	en.cl = st.cl;
	return (en);
}

t_pst	next_y(t_fdf f, t_pst st)
{
	t_pst	en;
	int		agl;

	agl = 30;
	en.x = st.x + (int)(f.du * cos(agl * M_PI / 180));
	en.y = st.y + (int)(f.du * sin(agl * M_PI / 180));
	en.cl = st.cl;
	return (en);
}
