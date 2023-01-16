/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:25 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/16 22:04:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_dmt	take_dmnt(char *map)
{
	int		fd;
	t_dmt	dm;

	fd = chck_opn(map);
	dm.ht = map_len(fd);
	fd = chck_opn(map);
	dm.wt = map_wt(fd);
	return (dm);
}
