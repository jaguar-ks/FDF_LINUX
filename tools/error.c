/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:17:34 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/07 14:33:31 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	error(int er)
{
	if (er == -2)
		ft_putstr_fd("Error: Incorect file format\n", 2);
	else if (er == -1)
		ft_putstr_fd("Error: Allocation faild\n", 2);
	else if (er == 0)
		ft_putstr_fd("Error: Invalid map\n", 2);
	else
		perror("Error");
	return (1);
}
