/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:20:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/05 15:03:20 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef	struct		s_array
{
	int				x;
	int				y;
	double			z;
	double			coord_x;
	double			coord_y;
	double			coord_z;
}					t_array;

typedef	struct		s_info
{
	unsigned int	map_size_x;
	unsigned int	map_size_y;
	int				zoom_in;
	int				zoom_out;
	double			gamma;
	double			alpha;
	double			beta;
	int				mouse_x;
	int				mouse_y;
	int				x_prev;
	int				y_prev;
	int				mouse_is_press;
	double			iso_mod;
	int				color;
	int				type;
	int				row;
	double			move_y;
	double			move_x;
	double			zoom;
	unsigned int	count;
	int				nbrs;
	int				lines;
	void			*mlx;
	void			*win;
	t_array			**arr;
}					t_info;

int					get_next_x(t_info *info, t_array **arr, int x, int i);
int					get_nbr_count(intmax_t len);

void				failure();
void				interface(t_info *info);
void				draw_map(t_info *info);
void				move_map(t_info *info, int direction);
void				zoom_map(t_info *info, int direction);
void				set_coords(t_info *info);
void				reset_map(t_info *info);
void				change_type(t_info *info);
void				modify_iso(t_info *info, int direction);
void				key_management(t_info *info);
void				get_array_values(t_info *info, int fd);
void				get_map_info(t_info *info, int fd);
void				initialize(t_info *info);
void				get_color(t_info *info, t_array **arr, int xy);

#endif
