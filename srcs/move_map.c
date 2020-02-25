/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:30:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/03 17:41:08 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_map(t_info *info, int direction)
{
	int i;

	i = 0;
	if (direction < 3)
		info->move_y = direction == 1 ? info->move_y - 10 : info->move_y + 10;
	if (direction < 3 && info->type == 2)
		info->move_x = direction == 1 ? info->move_x - 10 : info->move_x + 10;
	if (direction > 2)
		info->move_x = direction == 3 ? info->move_x - 10 : info->move_x + 10;
	if (direction > 2 && info->type == 2)
		info->move_y = direction == 4 ? info->move_y - 10 : info->move_y + 10;
	set_coords(info);
	mlx_clear_window(info->mlx, info->win);
	interface(info);
	draw_map(info);
}

void	zoom_map(t_info *info, int direction)
{
	int i;

	i = 0;
	info->zoom = direction == 1 ? info->zoom + 1 : info->zoom - 1;
	set_coords(info);
	mlx_clear_window(info->mlx, info->win);
	interface(info);
	draw_map(info);
}

void	reset_map(t_info *info)
{
	info->alpha = 0;
	info->beta = 0;
	info->gamma = 0;
	info->move_y = 0;
	info->move_x = 0;
	info->iso_mod = 1;
	info->zoom = 20;
	set_coords(info);
	mlx_clear_window(info->mlx, info->win);
	interface(info);
	draw_map(info);
}

void	modify_iso(t_info *info, int direction)
{
	if (direction == 1)
		info->iso_mod += 0.3;
	else
		info->iso_mod -= 0.3;
	set_coords(info);
	mlx_clear_window(info->mlx, info->win);
	interface(info);
	draw_map(info);
}
