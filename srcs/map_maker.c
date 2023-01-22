/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:41:39 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/22 19:40:08 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_len(char *ber)
{
	int		fd;
	int		len;
	int		err;
	char	buff[1];

	fd = open(ber, O_RDONLY);
	len = 0;
	err = read(fd, buff, 1);
	while (err > 0)
	{
		++len;
		err = read(fd, buff, 1);
	}
	if (err < 0 || fd < 0)
		error_control("map read Error\n");
	close(fd);
	return (len);
}

char	*map_reader(char *ber)
{
	int		fd;
	int		size;
	char	*rtn;

	size = map_len(ber);
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		error_control("mapfile open Error\n");
	rtn = (char *)malloc(sizeof(char) * (size + 1));
	if (!rtn || read(fd, rtn, size) < 0)
		error_control("building map Error\n");
	rtn[size] = '\0';
	close(fd);
	return (rtn);
}

char	**build_map(char *ber)
{
	char	**map;
	char	*tmp;

	tmp = map_reader(ber);
	check_components(tmp);
	map = ft_split(tmp, '\n');
	if (check_square(map) || check_wall(map))
		error_control("invalid map Error \n");
	path_finder(map);
	return (map);
}
