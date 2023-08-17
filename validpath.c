/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validpath.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 13:49:40 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 15:17:33 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validpath(char **map)
{
	int	valid;

	valid = 0;
	while (valid != 1)
	{
		valid = addp(map);
	}
}

char	addp(char **map)
{
	int		x;
	int		y;
	int		cntp;

	cntp = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				if (map[y - 1][x] == 'E' || map[y + 1][x] == 'E'
				|| map[y][x - 1] == 'E' || map[y][x + 1] == 'E')
					return (1);
				cntp = cntp + placingp(map, x, y);
			}
		x++;
		}
	y++;
	}
	if (cntp == 0)
		itsanerror();
	return (0);
}

int	placingp(char **map, int x, int y)
{
	int	cntp;

	cntp = 0;
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P')
	{
		map[y - 1][x] = 'P';
		cntp++;
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P')
	{
		map[y + 1][x] = 'P';
		cntp++;
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P')
	{
		map[y][x - 1] = 'P';
		cntp++;
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P')
	{
		map[y][x + 1] = 'P';
		cntp++;
	}
	return (cntp);
}
