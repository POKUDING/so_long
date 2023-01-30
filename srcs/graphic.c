/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:33:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/30 19:15:35 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	graphic_map(t_data data, t_info info, t_img img)
{
	int	x;
	int	y;
	char **map;

	map = data.map;
	y = 0;
	while(y < info.map_hegiht)
	{
		x = 0;
		while(x < info.map_width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_wall, x * 32, y * 32);
			else
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_ground, x * 32, y * 32);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_coin, x * 32 + 8, y * 32 + 8);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_front[0], x * 32 + 7, y * 32 + 4);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_closed, x * 32, y * 32);
			else if (map[y][x] == 'O')
				mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img.img_open, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
