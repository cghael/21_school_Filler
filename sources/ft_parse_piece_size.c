/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_piece_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:52:55 by cghael            #+#    #+#             */
/*   Updated: 2020/08/18 15:52:57 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_valid_piece_size(t_filler *filler, char **str)
{
	if (!ft_strequ(str[0], "Piece") \
		|| !ft_check_numbers_or_colon(str[1], 0) \
		|| !ft_check_numbers_or_colon(str[2], 1))
	{
		ft_free_two_dem_str(str);
		return (-1);
	}
	filler->token.h = ft_atoi(str[1]);
	filler->token.w = ft_atoi(str[2]);
	if (filler->token.h < 1 || filler->token.w < 1)
		return (-1);
	return (0);
}

int				ft_parse_piece_size(t_filler *filler)
{
	char	*line;
	char	**str;

	str = NULL;
	if (ft_get_next_line(filler->fd, &line) != 1 \
		|| ft_word_count(line, ' ') != 3 \
		|| !(str = ft_strsplit(line, ' '))
		|| ft_valid_piece_size(filler, str) < 0)
	{
		ft_strdel(&line);
		ft_free_two_dem_str(str);
		return (-1);
	}
	ft_strdel(&line);
	ft_free_two_dem_str(str);
	return (0);
}
