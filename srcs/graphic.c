/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:33:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/23 23:06:56 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	graphic_preset(t_data data, t_info info)
{
	int	x;
	int	y;

	(void)data;
	x = 0;
	y = 0;
	while(y < info.map_hegiht)
	{
		while(x < info.map_width)
		{
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr,info.img_wall.img,x * 32, y * 32);
			x++;
		}
		y++;
	}
}
