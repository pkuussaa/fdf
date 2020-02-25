/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:29:42 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/03 16:31:21 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_next_x(t_info *info, t_array **arr, int x, int i)
{
	if (arr[i]->y >= info->lines)
		return (i);
	i++;
	while (x != arr[i]->x)
		i++;
	return (i);
}

static	int	colors(double src, double dst)
{
	int val;

	val = src - dst;
	if (src == 0 || dst == 0)
		return (0XBE33FF);
	if (val > 0)
		return (0XFF3333);
	else if (val < 0)
		return (0X9FFF33);
	else
		return (0XFFD733);
	return (0);
}

void		get_color(t_info *info, t_array **arr, int xy)
{
	if (xy == 1)
	{
		if (arr[0]->z == 0 && arr[1]->z == 0)
		{
			info->color = 0X3F33FF;
			return ;
		}
		info->color = colors(arr[0]->z, arr[1]->z);
	}
	else
	{
		if (arr[0]->z == 0 && arr[get_next_x(info, arr, arr[0]->x, 0)]->z == 0)
		{
			info->color = 0X3F33FF;
			return ;
		}
		info->color = colors(arr[0]->z,
		arr[get_next_x(info, arr, arr[0]->x, 0)]->z);
	}
}
