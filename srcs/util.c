/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:55:21 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/22 20:55:36 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
