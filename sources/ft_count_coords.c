/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:41:25 by cghael            #+#    #+#             */
/*   Updated: 2020/08/17 15:41:27 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_check_for_min(t_filler *filler, t_coord delta, int sqr)
{
	if (filler->token.min_sqr == 0 || filler->token.min_sqr > sqr)
	{
		filler->token.min_sqr = sqr;
		filler->token.min_x = delta.x;
		filler->token.min_y = delta.y;
	}
}

static int		ft_check_map_size_n_free_point(t_filler *filler, \
													t_coord delta, t_coord tmp)
{
	if (((delta.y + tmp.y < 0 \
		|| delta.x + tmp.x < 0 \
		|| delta.y + tmp.y >= filler->map.h \
		|| delta.x + tmp.x >= filler->map.w) \
		|| (filler->map.coord[delta.y + tmp.y][delta.x + tmp.x].name != FREE)))
		return (TRUE);
	return (FALSE);
}

static int		ft_can_token_stand(t_filler *filler, t_coord delta, \
																t_coord p_token)
{
	int		sqr;
	t_coord	tmp;

	sqr = 0;
	tmp.y = 0;
	while (tmp.y < filler->token.h)
	{
		tmp.x = 0;
		while (tmp.x < filler->token.w)
		{
			if ((tmp.x != p_token.x || tmp.y != p_token.y) \
				&& filler->token.coord[tmp.y][tmp.x] == '*')
			{
				if (ft_check_map_size_n_free_point(filler, delta, tmp))
					return (FALSE);
				else if (filler->map.coord[delta.y + tmp.y]\
												[delta.x + tmp.x].name == FREE)
					sqr += filler->map.coord[delta.y + tmp.y]\
														[delta.x + tmp.x].num;
			}
			tmp.x++;
		}
		tmp.y++;
	}
	return (sqr);
}

static void		ft_put_token(t_filler *filler, t_coord p_map)
{
	t_coord	p_token;
	int		sqr;
	t_coord	delta;

	p_token.y = 0;
	while (p_token.y < filler->token.h)
	{
		p_token.x = 0;
		while (p_token.x < filler->token.w)
		{
			if (filler->token.coord[p_token.y][p_token.x] == '*')
			{
				delta.x = p_map.x - p_token.x;
				delta.y = p_map.y - p_token.y;
				sqr = ft_can_token_stand(filler, delta, p_token);
				if (sqr)
					ft_check_for_min(filler, delta, sqr);
			}
			p_token.x++;
		}
		p_token.y++;
	}
}

void			ft_count_coords(t_filler *filler)
{
	t_coord	p_map;

	filler->token.min_sqr = 0;
	filler->token.min_x = 0;
	filler->token.min_y = 0;
	p_map.y = 0;
	while (p_map.y < filler->map.h)
	{
		p_map.x = 0;
		while (p_map.x < filler->map.w)
		{
			if (filler->map.coord[p_map.y][p_map.x].name == filler->player)
				ft_put_token(filler, p_map);
			p_map.x++;
		}
		p_map.y++;
	}
}
