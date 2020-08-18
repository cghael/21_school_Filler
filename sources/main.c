/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:59:01 by cghael            #+#    #+#             */
/*   Updated: 2020/08/04 12:59:04 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_check_plateau_n_piece(t_filler *filler)
{
	if (ft_parse_plateau_size(filler) < 0 \
		|| ft_create_map(filler) < 0 \
		|| ft_parse_map(filler) < 0 \
		|| ft_parse_piece_size(filler) < 0 \
		|| ft_parse_piece(filler) < 0)
	{
		ft_free_filler(filler);
		return (FALSE);
	}
	return (TRUE);
}

int			main(void)
{
	t_filler	*filler;

	if (!(filler = ft_parse_player(FD)))
		return (ft_error_msg(ERROR));
	while (TRUE == ft_check_plateau_n_piece(filler))
	{
		ft_make_map(filler);
		ft_count_coords(filler);
		ft_printf("%d %d\n", filler->token.min_y, filler->token.min_x);
		ft_free_filler(filler);
	}
	free(filler);
	return (1);
}
