/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:19:52 by cghael            #+#    #+#             */
/*   Updated: 2020/08/07 14:19:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_create_map(t_filler *filler)
{
	unsigned int	i;

	i = 0;
	if (!(filler->map.coord = (t_point**)ft_memalloc(sizeof(t_point*) * \
																filler->map.h)))
		return (-1);
	while (i < filler->map.h)
	{
		if (!(filler->map.coord[i] = (t_point*)ft_memalloc(sizeof(t_point) * \
																filler->map.w)))
		{
			while (--i > 0)
				free(filler->map.coord[i]);
			free(filler->map.coord);
			filler->map.coord = NULL;
			return (-1);
		}
		filler->map.coord[i]->name = FREE;
		filler->map.coord[i]->num = 0;
		i++;
	}
	return (0);
}
