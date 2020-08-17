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
# define ERROR		"Error: Bad input\n"
# define FALSE		0
# define FD			0
# define FREE		'.'

# include "ft_printf.h"
# include "ft_get_next_line.h"

typedef struct		s_point
{
	char			name;
	int				num;
}					t_point;

typedef struct		s_plat
{
	int				h;
	int				w;
	t_point			**coord;
}					t_plat;

typedef struct		s_piece
{
	int				h;
	int				w;
	char			**coord;
}					t_piece;

typedef struct		s_filler
{

	char			player;
	char			enemy;
	int				fd;
	t_plat			map;
	t_piece			token;
}					t_filler;

t_filler			*ft_parse_player(int fd);
int					ft_parse_plateau_size(t_filler *filler);
int					ft_create_map(t_filler *filler);
int					ft_error_msg(char *str);
int					ft_parse_map(t_filler *filler);
int					ft_parse_piece_size(t_filler *filler);
int					ft_check_numbers_or_colon(const char *str, int c_flag);
int					ft_parse_piece(t_filler *filler);
void				ft_free_filler(t_filler *filler);
void				ft_make_map(t_filler *filler);
void				ft_count_coords(t_filler *filler);

#endif
