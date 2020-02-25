/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:12:39 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/03 17:40:40 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_action(int key, void *param)
{
	t_info *info;

	info = param;
	if (key == 24)
		modify_iso(info, 1);
	if (key == 27)
		modify_iso(info, 2);
	if (key == 18 && info->type != 1)
		change_type(info);
	if (key == 19 && info->type != 2)
		change_type(info);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == UP)
		move_map(info, 1);
	if (key == DOWN)
		move_map(info, 2);
	if (key == LEFT)
		move_map(info, 3);
	if (key == RIGHT)
		move_map(info, 4);
	if (key == 15)
		reset_map(info);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_info *info;

	info = param;
	info->x_prev = info->mouse_x;
	info->y_prev = info->mouse_y;
	info->mouse_x = x;
	info->mouse_y = y;
	if (info->mouse_is_press == 1 || info->mouse_is_press == 2)
	{
		info->alpha += info->mouse_is_press == 1 ?
		(y - info->y_prev) * 0.003 : 0;
		info->beta += info->mouse_is_press == 2 ?
		(x - info->x_prev) * 0.003 : 0;
		info->gamma += (x - info->x_prev) * 0.008;
		set_coords(info);
		mlx_clear_window(info->mlx, info->win);
		interface(info);
		draw_map(info);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_info *info;

	info = param;
	info->mouse_is_press = 0;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_info	*info;

	info = param;
	(void)x;
	(void)y;
	if (button == 1)
		info->mouse_is_press = 1;
	if (button == 2)
		info->mouse_is_press = 2;
	if (button == 4)
		zoom_map(info, 1);
	if (button == 5)
		zoom_map(info, 2);
	return (0);
}

void	key_management(t_info *info)
{
	mlx_hook(info->win, 2, 0, key_action, info);
	mlx_hook(info->win, 4, 0, mouse_press, info);
	mlx_hook(info->win, 5, 0, mouse_release, info);
	mlx_hook(info->win, 6, 0, mouse_move, info);
}
