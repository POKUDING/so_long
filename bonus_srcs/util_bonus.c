/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JUN <JUN@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:55:21 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/11 02:07:01 by JUN              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_move(t_data *data)
{
	data->move++;
	graphic_move_cnt(*data, *data->img);
	ft_putnbr_fd(data->move, 1);
	write(1, "\n", 1);
}

void	error_control(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

void	free_box(char **box)
{
	int	i;

	i = 0;
	while (box[i])
		free(box[i++]);
	free(box[i]);
	free(box);
}
