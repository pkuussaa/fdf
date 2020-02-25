/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:45:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/03 15:57:27 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			rotate_x(t_info *info, t_array **arr)
{
	double y;

	y = arr[0]->coord_y;
	arr[0]->coord_y = y * cos(info->alpha) - arr[0]->coord_z * sin(info->alpha);
	arr[0]->coord_z = arr[0]->coord_z * cos(info->alpha) +
	arr[0]->coord_y * sin(info->alpha);
}

void			rotate_y(t_info *info, t_array **arr)
{
	double	x;

	x = arr[0]->coord_x;
	arr[0]->coord_x = x * cos(info->beta) + arr[0]->z * sin(info->beta);
	arr[0]->coord_z = arr[0]->coord_z * cos(info->beta) - x * sin(info->beta);
}

void			rotate_z(t_info *info, t_array **arr)
{
	double	x;
	double	y;

	x = arr[0]->coord_x;
	y = arr[0]->coord_y;
	arr[0]->coord_x = x * cos(info->gamma) - y * sin(info->gamma);
	arr[0]->coord_y = x * sin(info->gamma) + y * cos(info->gamma);
}

static	void	move_and_iso(t_info *info, t_array **arr, int i, double holder)
{
	arr[i]->coord_x += info->move_x;
	arr[i]->coord_y += info->move_y;
	if (info->type == 2)
	{
		holder = info->arr[i]->coord_x;
		arr[i]->coord_x = (arr[i]->coord_x -
		arr[i]->coord_y) * cos(0.523599);
		arr[i]->coord_y = -arr[i]->coord_z +
		(holder + arr[i]->coord_y) * sin(0.523599);
	}
}

void			set_coords(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->nbrs)
	{
		info->arr[i]->coord_z = info->arr[i]->z * info->iso_mod;
		info->arr[i]->coord_x = info->arr[i]->x * info->zoom;
		info->arr[i]->coord_x -= (info->row * info->zoom) / 2;
		info->arr[i]->coord_y = info->arr[i]->y * info->zoom;
		info->arr[i]->coord_y -= (info->lines * info->zoom) / 2;
		if (info->type == 1)
		{
			rotate_y(info, info->arr + i);
			rotate_x(info, info->arr + i);
		}
		else
			rotate_z(info, info->arr + i);
		move_and_iso(info, info->arr, i, 0);
		i++;
	}
}
