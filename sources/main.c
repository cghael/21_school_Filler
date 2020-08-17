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

#include <fcntl.h>

int			ft_check_plateau_n_piece(t_filler *filler)
{
	if (ft_parse_plateau_size(filler) < 0 \
		|| ft_create_map(filler) < 0 \
		|| ft_parse_map(filler) < 0 \
		|| ft_parse_piece_size(filler) < 0 \
		|| ft_parse_piece(filler) < 0)
	{
		ft_free_filler(filler);
		return (ft_error_msg(ERROR));
	}
	return (1);
}

int			main(void)
{
	t_filler	*filler;

		int fd; //todo del
		fd = open("/Users/cghael/21_school_Filler/test", O_RDONLY); //todo del
	if (!(filler = ft_parse_player(fd))) //todo FD
		return (ft_error_msg(ERROR));
	while (ft_check_plateau_n_piece(filler) > 0)
	{
		//ft_make_map(filler);
		//ft_count_coords(filler);
		//ft_print_coords(filler);
		ft_free_filler(filler);
	}
	return (1);
}

