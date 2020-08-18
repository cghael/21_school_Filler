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

static void	ft_fill_map(t_filler *filler, unsigned int j)
{
	int i;

	i = 0;
	while (i < filler->map.w)
	{
		filler->map.coord[j][i].name = FREE;
		filler->map.coord[j][i].num = 0;
		i++;
	}
}

int			ft_create_map(t_filler *filler)
{
	int	j;

	j = 0;
	if (!(filler->map.coord = (t_point**)ft_memalloc(sizeof(t_point*) * \
																filler->map.h)))
		return (-1);
	while (j < filler->map.h)
	{
		if (!(filler->map.coord[j] = (t_point*)ft_memalloc(sizeof(t_point) * \
																filler->map.w)))
		{
			while (--j > 0)
				free(filler->map.coord[j]);
			free(filler->map.coord);
			filler->map.coord = NULL;
			return (-1);
		}
		ft_fill_map(filler, j);
		j++;
	}
	return (0);
}
