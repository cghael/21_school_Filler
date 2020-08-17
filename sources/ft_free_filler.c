/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:04:16 by cghael            #+#    #+#             */
/*   Updated: 2020/08/17 12:04:18 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_free_filler(t_filler *filler)
{
	while (filler->map.h)
	{
		if (filler->map.coord[filler->map.h - 1])
			free(filler->map.coord[filler->map.h - 1]);
		filler->map.coord[filler->map.h - 1] = NULL;
		filler->map.h--;
	}
	if (filler->map.coord)
		free(filler->map.coord);
	filler->map.coord = NULL;
	while (filler->token.h)
	{
		if (filler->token.coord[filler->token.h - 1])
			free(filler->token.coord[filler->token.h - 1]);
		filler->token.coord[filler->token.h - 1] = NULL;
		filler->token.h--;
	}
	if (filler->token.coord)
		free(filler->token.coord);
	filler->token.coord = NULL;
}
