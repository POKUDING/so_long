/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:08:01 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 15:08:28 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_coin(t_data *data, t_img img, int x, int y)
{
	data->coins--;
	my_put_img(*data->info, img.img_ground, x * 32, y * 32);
	data->map[y][x] = '0';
	if (data->coins == 0)
	{
		my_put_img(*data->info, img.img_open,
			data->exit_x * 32, data->exit_y * 32);
	}
}

void	move_down(t_data *data, t_info info, t_img img)
{
	if (data->status == 0 || data->status == 1)
		return ;
	data->status = 2;
	if (data->map[data->player_y + 1][data->player_x] == '1' || \
		(data->coins != 0 && \
		data->map[data->player_y + 1][data->player_x] == 'E'))
		return ;
	if (data->coins == 0 && \
		data->map[data->player_y + 1][data->player_x] == 'E')
		data->status = 0;
	print_move(data);
	if (data->map[data->player_y + 1][data->player_x] == 'C')
		get_coin(data, img, data->player_x, data->player_y + 1);
	my_put_img(info, img.img_ground, data->player_x * 32, data->player_y * 32);
	data->player_y++;
	my_put_img(info, img.img_front[0],
		data->player_x * 32 + 7, data->player_y * 32 + 4);
}

void	move_up(t_data *data, t_info info, t_img img)
{
	if (data->status == 0 || data->status == 1)
		return ;
	data->status = 8;
	if (data->map[data->player_y - 1][data->player_x] == '1' || \
		(data->coins != 0 && \
		data->map[data->player_y - 1][data->player_x] == 'E'))
		return ;
	if (data->coins == 0 && \
		data->map[data->player_y - 1][data->player_x] == 'E')
		data->status = 0;
	print_move(data);
	if (data->map[data->player_y - 1][data->player_x] == 'C')
		get_coin(data, img, data->player_x, data->player_y - 1);
	my_put_img(info, img.img_ground, data->player_x * 32, data->player_y * 32);
	data->player_y--;
	my_put_img(info, img.img_front[0],
		data->player_x * 32 + 7, data->player_y * 32 + 4);
}

void	move_right(t_data *data, t_info info, t_img img)
{
	if (data->status == 0 || data->status == 1)
		return ;
	data->status = 6;
	if (data->map[data->player_y][data->player_x + 1] == '1' || \
		(data->coins != 0 && \
		data->map[data->player_y][data->player_x + 1] == 'E'))
		return ;
	if (data->coins == 0 && \
		data->map[data->player_y][data->player_x + 1] == 'E')
		data->status = 0;
	print_move(data);
	if (data->map[data->player_y][data->player_x + 1] == 'C')
		get_coin(data, img, data->player_x + 1, data->player_y);
	my_put_img(info, img.img_ground, data->player_x * 32, data->player_y * 32);
	data->player_x++;
	my_put_img(info, img.img_front[0],
		data->player_x * 32 + 7, data->player_y * 32 + 4);
}

void	move_left(t_data *data, t_info info, t_img img)
{
	if (data->status == 0 || data->status == 1)
		return ;
	data->status = 4;
	if (data->map[data->player_y][data->player_x - 1] == '1' || \
		(data->coins != 0 && \
		data->map[data->player_y][data->player_x - 1] == 'E'))
		return ;
	if (data->coins == 0 && \
		data->map[data->player_y][data->player_x - 1] == 'E')
		data->status = 0;
	print_move(data);
	if (data->map[data->player_y][data->player_x - 1] == 'C')
		get_coin(data, img, data->player_x - 1, data->player_y);
	my_put_img(info, img.img_ground, data->player_x * 32, data->player_y * 32);
	data->player_x--;
	my_put_img(info, img.img_front[0],
		data->player_x * 32 + 7, data->player_y * 32 + 4);
}
