/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:39:01 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/10 20:23:59 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libtool/libft.h"
# include "../mlx/mlx.h"

/*the map demantions*/
typedef struct f_dmt
{
	int	ht;
	int wt;
}	t_dmt;
/*****************************/
/*read the data from the file*/
typedef struct f_rd
{
	char	**y;
	char	**x;
	char	**z;
}	t_rd;
/*****************************/
/*the information needed to drow the map*/
typedef struct f_inf
{
	int			x;
	int			y;
	int			z;
	long int	cl;
}	t_inf;
/****************************/
/*position*/
typedef struct f_pst
{
	int	i;
	int	j;
	int	z;
}	t_pst;
/****************************/
/*manipulation of crdnt list*/
int			error(int er);
// t_crdnts	*new_node(char **x, int y);
// t_crdnts	*lst_node(t_crdnts *hd);
// void		add_node_f(t_crdnts **hd, t_crdnts *new);
// void		add_node_b(t_crdnts **hd, t_crdnts *new);
// void		del_node(t_crdnts *nd);
// void		clear_nodes(t_crdnts **hd);
/****************************/
/*parcing*/
t_inf		**read_map(char *mp, char **map);
t_dmt		take_dmnt(char *map);
int			mtx_len(char **mx);
int			chck_opn(char *fl);
int			chck_map(char **map);
/****************************/
// /*drawing*/
// void		*open_win(void *mlx, t_crdnts *hd, char *ttl);
// t_pst		draw_x(void *mlx, void *win, t_pst st, int du);
// t_pst		draw_y(void *mlx, void *win, t_pst st, int du);
long int			hex_to_dec(char *s);
// t_inf		take_inf(t_crdnts *hd);
// void		draw_map(t_crdnts *hd, void *mlx, void *win);
// /****************************/

#endif
