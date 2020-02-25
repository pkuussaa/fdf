/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:16:29 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/05 17:08:16 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	init_arr(t_info *info, char *str, int *index, int *y)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (!(info->arr[*index] = (t_array *)malloc(sizeof(t_array))))
				failure();
			counter++;
			info->arr[*index]->x = counter;
			info->arr[*index]->y = *y;
			info->arr[*index]->z = ft_atoi(str + i);
			i += get_nbr_count((intmax_t)ft_atoi(str + i));
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			*index += 1;
		}
		else
			i++;
	}
	if (info->arr[*index - 1]->x != info->row)
		failure();
}

void			get_array_values(t_info *info, int fd)
{
	char	*line;
	int		index;
	int		y;

	index = 0;
	y = 0;
	if (!(info->arr = (t_array **)malloc(sizeof(t_array *) * info->nbrs)))
		failure();
	while (get_next_line(fd, &line) > 0)
	{
		init_arr(info, line, &index, &y);
		y++;
		ft_strdel(&line);
	}
	set_coords(info);
}

static	void	get_length(t_info *info, char *str, int *i)
{
	if (info->lines == 0)
		info->row += 1;
	info->nbrs++;
	*i += get_nbr_count((intmax_t)ft_atoi(str + *i));
	while (str[*i] != ' ' && str[*i] != '\0')
		*i += 1;
}

void			get_map_info(t_info *info, int fd)
{
	char			*line;
	int				i;
	unsigned int	count;

	info->nbrs = 0;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			failure();
		i = 0;
		while (line[i])
		{
			if (line[i] != ' ')
				get_length(info, line, &i);
			else
				i++;
			count++;
		}
		info->lines++;
		ft_strdel(&line);
	}
	info->count = count;
	close(fd);
}

void			initialize(t_info *info)
{
	info->gamma = 0;
	info->alpha = 0;
	info->beta = 0;
	info->mouse_x = 0;
	info->mouse_y = 0;
	info->mouse_is_press = 0;
	info->iso_mod = 1;
	info->type = 1;
	info->move_y = 0;
	info->move_x = 0;
	info->zoom = 20;
	info->lines = -1;
	info->row = 0;
}
