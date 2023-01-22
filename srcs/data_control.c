/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:22 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/22 20:54:22 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_components(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (data->map[x][y])
	{
		x = 1;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[x][y] == 'C')
				data->coins++;
			x++;
		}
		y++;
	}
}

void	data_init(t_data *data, char **map)
{
	data->map = map;
	data->coins = 0;
	find_componentes(data);
	data->move = 0;
}

int	key_event(int key, t_data *data)
{
	if (key == 1)
		data->player_x++;
	if (key == 2)
		data->player_x--;
	if (key == 3)
		data->player_y++;
	if (key == 4)
		data->player_y--;
}
