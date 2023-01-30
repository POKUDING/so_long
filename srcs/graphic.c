/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:33:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/30 20:05:28 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_put_img(t_info info, void *img, int x, int y)
{
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img, x, y);
}

void	graphic_map(t_data data, t_info info, t_img img)
{
	int		x;
	int		y;

	y = 0;
	while (y < info.map_hegiht)
	{
		x = 0;
		while (x < info.map_width)
		{
			if (data.map[y][x] == '1')
				my_put_img(info, img.img_wall, x * 32, y * 32);
			else
				my_put_img(info, img.img_ground, x * 32, y * 32);
			if (data.map[y][x] == 'C')
				my_put_img(info, img.img_coin, x * 32 + 8, y * 32 + 8);
			else if (data.map[y][x] == 'P')
				my_put_img(info, img.img_front[0], x * 32 + 7, y * 32 + 4);
			else if (data.map[y][x] == 'E')
				my_put_img(info, img.img_closed, x * 32, y * 32);
			else if (data.map[y][x] == 'O')
				my_put_img(info, img.img_open, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
