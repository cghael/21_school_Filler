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

int			ft_check_plateau_n_pice()
{
	ft_parse_plateau_size(); //todo cannot be 0
	ft_parse_map();
	ft_check_plateau_map();
	ft_parse_piece_size(); //todo cannot be 0
	ft_parse_peice();
}

int			main(void)
{
	t_filler	*filler;

	filler = ft_parse_player();
	while (ft_check_plateau_n_pice() == TRUE)
	{
		//count coords
		//print coords
		//free struct
	}
	return (0);
}
