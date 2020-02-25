/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/02/05 16:52:53 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			failure(void)
{
	ft_putendl("error.");
	exit(EXIT_FAILURE);
}

static	void	interface_second(t_info *info)
{
	char *str;

	str = ft_strdup("+ , - to change altitude");
	mlx_string_put(info->mlx, info->win, 10, 100, 0XFFFF, str);
	free(str);
	str = ft_strdup("Reset, r");
	mlx_string_put(info->mlx, info->win, 10, 120, 0XFFFF, str);
	free(str);
	str = info->type == 1 ?
	ft_strdup("Change x axle angle, mouse left button + move mouse.")
	: ft_strdup("Rotate figure with left or right mouse button + mouse move.");
	mlx_string_put(info->mlx, info->win, 10, 140, 0XFFFF, str);
	free(str);
	if (info->type == 1)
	{
		str =
		ft_strdup("Change y axle angle, mouse right button + move mouse.");
		mlx_string_put(info->mlx, info->win, 10, 160, 0XFFFF, str);
		free(str);
	}
}

void			interface(t_info *info)
{
	char *str;

	str = ft_strdup("F D F");
	mlx_string_put(info->mlx, info->win, 10, 0, 0XFFFF, str);
	free(str);
	str = ft_strdup("Move figure by using arrow keys.");
	mlx_string_put(info->mlx, info->win, 10, 20, 0XFFFF, str);
	free(str);
	str = info->type == 1 ?
	ft_strdup("Press 2 to change projection to isometric")
	: ft_strdup("Press 1 to change projection to parallel");
	mlx_string_put(info->mlx, info->win, 10, 40, 0XFFFF, str);
	free(str);
	str = ft_strdup("Zoom with mouse scroll.");
	mlx_string_put(info->mlx, info->win, 10, 60, 0XFFFF, str);
	free(str);
	str = info->type == 1 ? ft_strdup("Type: Parallel.") :
	ft_strdup("Type: Isometric.");
	mlx_string_put(info->mlx, info->win, 10, 80, 0XFFFF, str);
	free(str);
	interface_second(info);
}

static	void	map_size(t_info *info)
{
	if (info->count * 2 >= 800)
	{
		info->map_size_x = info->count * 2 < 2500 ? info->count * 2 : 2500;
		info->map_size_y = info->count * 2 < 2500 ? info->count * 2 : 1400;
	}
	else
	{
		info->map_size_x = 800;
		info->map_size_y = 800;
	}
}

int				main(int argc, char **argv)
{
	t_info		*info;
	int			fd;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		failure();
	if (argc == 2)
	{
		initialize(info);
		info->mlx = mlx_init();
		fd = open(argv[1], O_RDONLY);
		get_map_info(info, fd);
		fd = open(argv[1], O_RDONLY);
		get_array_values(info, fd);
		map_size(info);
		info->win = mlx_new_window(info->mlx, info->map_size_x,
		info->map_size_y, "Fdf");
		interface(info);
		draw_map(info);
		key_management(info);
		mlx_loop(info->mlx);
	}
	else
		ft_putendl("usage: ./fdf source_file");
}
