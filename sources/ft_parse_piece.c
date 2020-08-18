/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:51:59 by cghael            #+#    #+#             */
/*   Updated: 2020/08/18 15:52:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_token(t_filler *filler)
{
	int j;
	int i;

	j = 0;
	while (j < filler->token.h)
	{
		i = 0;
		while (i < filler->token.w)
		{
			if (filler->token.coord[j][i] != '.' \
				&& filler->token.coord[j][i] != '*')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int				ft_parse_piece(t_filler *filler)
{
	int i;

	i = 0;
	if (!(filler->token.coord = (char**)ft_memalloc(sizeof(char*) * \
														filler->token.h + 1)))
		return (-1);
	while (i < filler->token.h)
	{
		if (ft_get_next_line(filler->fd, &filler->token.coord[i]) != 1 \
			|| (int)ft_strlen(filler->token.coord[i]) != filler->token.w)
			return (-1);
		i++;
	}
	if (ft_check_token(filler) < 0)
		return (-1);
	return (0);
}
