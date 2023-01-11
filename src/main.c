/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/11 17:26:52 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	f;
	char	*map;

	if (ac == 2)
	{
		f.crd = read_map(av[1], &map);
		f.dm = take_dmnt(map);
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, W_HT, W_WT, av[1]);
		draw_map(f);
		// st.x = 50;
		// en.x = 170;
		// st.y = 150;
		// en.y = 360;
		// st.cl = 0xFFFF;
		// en.cl = 0xFFFFFF;
		// draw_line(f, st, en);
		mlx_loop(f.mlx);
	}
}
