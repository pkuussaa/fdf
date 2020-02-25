/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:28:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/03 17:40:33 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_type(t_info *info)
{
	if (info->type == 1)
	{
		write(1, "type changed to isometric\n", 26);
		info->type = 2;
		info->alpha = 0;
		info->beta = 0;
		info->gamma = 0;
		set_coords(info);
		mlx_clear_window(info->mlx, info->win);
		interface(info);
		draw_map(info);
	}
	else if (info->type == 2)
	{
		write(1, "type changed to parallel\n", 25);
		info->type = 1;
		info->alpha = 0;
		info->beta = 0;
		info->gamma = 0;
		set_coords(info);
		mlx_clear_window(info->mlx, info->win);
		interface(info);
		draw_map(info);
	}
}
