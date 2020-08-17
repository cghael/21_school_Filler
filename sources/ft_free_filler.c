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
		free(filler->map.coord[filler->map.h - 1]);
		filler->map.h--;
	}
	free(filler->map.coord);
	while (filler->token.h)
	{
		free(filler->token.coord[filler->token.h - 1]);
		filler->token.h--;
	}
	free(filler->token.coord);
	free(filler);
}
