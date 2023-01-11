/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:25 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/10 20:30:08 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_dmt	take_dmnt(char *map)
{
	t_dmt	dm;
	t_rd	rd;

	rd.y = ft_split(map, '\n');
	dm.ht = mtx_len(rd.y);
	rd.x = ft_split(rd.y[0], ' ');
	dm.wt = mtx_len(rd.x);
	deallocate(rd.y);
	deallocate(rd.x);
	free(map);
	return (dm);
}
