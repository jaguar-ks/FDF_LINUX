/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:17:34 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 14:08:15 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	error(int er)
{
	if (er == -2)
		ft_putstr_fd("Error: Incorect file format\nNeed an [.fdf] file\n", 2);
	else if (er == -3)
		ft_putstr_fd("Error: Invalid map\nCheck the size or the colors\n", 2);
	else
		perror("Error");
	return (1);
}
