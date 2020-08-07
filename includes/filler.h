/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:58:26 by cghael            #+#    #+#             */
/*   Updated: 2020/08/04 12:58:29 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# define TRUE		1
# define FALSE		0
# define FD			0

# include "ft_printf.h"
# include "ft_get_next_line.h"

typedef struct		s_filler
{
	char			player;
	int				fd;
}					t_filler;

t_filler			*ft_parse_player(int fd);

#endif
