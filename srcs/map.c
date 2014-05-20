/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:26:38 by msagodir          #+#    #+#             */
/*   Updated: 2014/01/18 18:40:56 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wolf3d.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void		init_map(t_env *e)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	e->world_map = (int**)malloc(sizeof(int*) * MAP_HEIGHT);
	fd = open("./map/map.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Map not found", 2);
		return ;
	}
	while (get_next_line(fd, &buff) == 1)
	{
		e->world_map[i] = ft_strsplittoint(buff, ' ');
		free(buff);
		i++;
	}
	close(fd);
}
