/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/17 01:11:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	close_key(int key, t_fdf *f)
{
	if (key == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

int	close_ms(t_fdf *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	f;
	int		i;

	if (ac == 2)
	{
		f.dm = take_dmnt(av[1]);
		f.crd = read_map(av[1], f);
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, W_HT, W_WT, av[1]);
		draw_map(f);
		mlx_key_hook(f.win, close_key, &f);
		mlx_hook(f.win, 17, 0, close_ms, &f);
		mlx_loop(f.mlx);
		i = -1;
		while (f.crd[++i])
			free(f.crd[i]);
		free(f.crd);
	}
	else
		ft_putendl_fd("Error: To many or few arguments", 2);
}
