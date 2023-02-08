/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:55:21 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 15:07:14 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_move(t_data *data)
{
	data->move++;
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
