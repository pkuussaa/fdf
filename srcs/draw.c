/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/14 19:03:23 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


double	*init_list(double start_x, double start_y, double end_x,
													double end_y)
{
	double *arr;

	if (!(arr = (double *)malloc(sizeof(double) * 4)))
		return (0);
	arr[0] = start_x;
	arr[1] = start_y;
	arr[2] = end_x;
	arr[3] = end_y;
	return (arr);
}

void	line_high(t_info *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = x < 0 ? -1 : 1;
	if (x < 0)
		x = -x;
	d = 2 * x - y;
	while (arr[1] < arr[3])
	{
		mlx_pixel_put(info->mlx, info->win, arr[0] + info->map_size_x / 2,
		arr[1] + info->map_size_y / 2, info->color);
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * y;
		}
		d += 2 * x;
		arr[1]++;
	}
	free(arr);
}

void	line_low(t_info *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = y < 0 ? -1 : 1;
	if (y < 0)
		y = -y;
	d = (2 * y) - x;
	while (arr[0] < arr[2])
	{
		mlx_pixel_put(info->mlx, info->win, arr[0] + info->map_size_x / 2,
		arr[1] + info->map_size_y / 2, info->color);
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * x;
		}
		d += 2 * y;
		arr[0]++;
	}
	free(arr);
}

void	bresenham_algorithm(t_info *info, double *arr)
{
	double	y_abs;
	double	x_abs;

	y_abs = arr[3] - arr[1] > 0 ? arr[3] - arr[1] : (arr[3] - arr[1]) * -1;
	x_abs = arr[2] - arr[0] > 0 ? arr[2] - arr[0] : -(arr[2] - arr[0]);
	if (y_abs < x_abs)
	{
		if (arr[0] > arr[2])
			line_low(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_low(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	else
	{
		if (arr[1] > arr[3])
			line_high(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_high(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	free(arr);
}

void	draw_map(t_info *info)
{
	int i;

	i = 0;
	while (i < info->nbrs)
	{
		if (i < info->nbrs - 1)
			if (info->arr[i]->x < info->arr[i + 1]->x)
			{
				get_color(info, info->arr + i, 1);
				bresenham_algorithm(info, init_list(info->arr[i]->coord_x,
				info->arr[i]->coord_y, info->arr[i + 1]->coord_x,
				info->arr[i + 1]->coord_y));
			}
		get_color(info, info->arr + i, 2);
		bresenham_algorithm(info, init_list(info->arr[i]->coord_x,
		info->arr[i]->coord_y, info->arr[get_next_x(info, info->arr,
		info->arr[i]->x, i)]->coord_x, info->arr[get_next_x(info, info->arr,
		info->arr[i]->x, i)]->coord_y));
		i++;
	}
	i = 0;
	info->color = 0XFF3333;
}
