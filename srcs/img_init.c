/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:54:13 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/02 15:11:32 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_preset(t_img *img, t_info *info)
{
	img->img_ground = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/sand.xpm", &img->width, &img->height);
	img->img_wall = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/wall.xpm", &img->width, &img->height);
	img->img_closed = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/close32.xpm", &img->width, &img->height);
	img->img_open = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/open32.xpm", &img->width, &img->height);
	img->img_front[0] = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/front_0.xpm", &img->width, &img->height);
	img->img_front[1] = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/front_1.xpm", &img->width, &img->height);
	player_img_preset(img, info);
	coin_img_preset(img, info);
}

void	player_img_preset(t_img *img, t_info *info)
{
	img->img_back[0] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/back_0.xpm", &img->width, &img->height);
	img->img_back[1] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/back_1.xpm", &img->width, &img->height);
	img->img_right[0] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/right_0.xpm", &img->width, &img->height);
	img->img_right[1] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/right_1.xpm", &img->width, &img->height);
	img->img_right[2] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/right_2.xpm", &img->width, &img->height);
	img->img_left[0] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/left_0.xpm", &img->width, &img->height);
	img->img_left[1] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/left_1.xpm", &img->width, &img->height);
	img->img_left[2] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/left_2.xpm", &img->width, &img->height);
}
void	coin_img_preset(t_img *img, t_info *info)
{
	img->img_coin[0] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/coin0.xpm", &img->width, &img->height);
	img->img_coin[1] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/coin1.xpm", &img->width, &img->height);
	img->img_coin[2] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/coin2.xpm", &img->width, &img->height);
	img->img_coin[3] = mlx_xpm_file_to_image(info->mlx_ptr,
		"./so_longxpm/coin3.xpm", &img->width, &img->height);
}
