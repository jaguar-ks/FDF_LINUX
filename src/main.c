/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/11 14:24:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_inf	**crd;
	char	*map;
	t_dmt	dm;

	if (ac == 2)
	{
		crd = read_map(av[1], &map);
		dm = take_dmnt(map);
		mlx = mlx_init();
		win = mlx_new_window(mlx, W_HT, W_WT, av[1]);
		printf("|%d|\n", init_drawing_unit(dm));
		mlx_loop(mlx);
	}
}
