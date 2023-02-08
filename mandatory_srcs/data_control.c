/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:22 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/04 16:13:35 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	info_preset(t_info *info, t_data data)
{
	int	i;

	i = 0;
	while (data.map[i])
		++i;
	info->map_hegiht = i;
	info->map_width = ft_strlen(data.map[0]);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->map_width * 32, info->map_hegiht * 32, "junhyupa");
}

void	find_components(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
			}
			else if (data->map[y][x] == 'C')
				data->coins++;
			else if (data->map[y][x] == '0')
				data->ground++;
		}
	}
}

void	data_preset(t_data *data, char *argv)
{
	data->map = build_map(argv);
	data->coins = 0;
	data->ground = 0;
	find_components(data);
	data->move = 0;
	data->status = 2;
}
