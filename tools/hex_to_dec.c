/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:52:13 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/15 23:08:15 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	hex_to_dec(char *s)
{
	int		i;
	int		r;

	i = 1;
	r = 0;
	while (s[++i])
	{
		if (ft_isalnum(s[i]))
		{
			if (!ft_isdigit(s[i]))
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = ft_tolower(s[i]);
				if (s[i] < 'a' || s[i] > 'f')
					exit(error(-3));
				r = (r * 16) + (s[i] - 87);
			}
			else
				r = (r * 16) + (s[i] - 48);
		}
		else
			break ;
	}
	return (r);
}
