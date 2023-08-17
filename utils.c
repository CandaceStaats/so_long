/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 12:56:56 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 15:37:55 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	itsanerror(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	**makeamap(int fd)
{
	char	**map;
	char	*templine;
	int		cnt;
	char	**tempmap;

	cnt = 0;
	map = malloc(sizeof(char *));
	tempmap = malloc(sizeof(char *));
	if (map == NULL || tempmap == NULL)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &templine) == 1)
	{
		map[cnt] = templine;
		map = allocatemap(map, cnt);
		tempmap[cnt] = ft_strdup(templine);
		tempmap = allocatemap(tempmap, cnt);
		cnt++;
	}
	isitvalid(map);
	validpath(tempmap);
	close(fd);
	return (map);
}

char	**allocatemap(char **oldmap, int cnt)
{
	char	**map;

	map = malloc(sizeof(char *) * (cnt + 2));
	if (map == NULL)
		exit(EXIT_FAILURE);
	map[cnt + 1] = NULL;
	while (cnt >= 0)
	{
		map[cnt] = oldmap[cnt];
		cnt--;
	}
	free(oldmap);
	return (map);
}

void	isitvalid(char **map)
{
	size_t	cnt;
	size_t	cnt2;

	cnt = ft_strlen(map[0]);
	cnt2 = 0;
	isitones(map[0]);
	while (map[cnt2] != NULL)
	{
		if (ft_strlen(map[cnt2]) != cnt)
			itsanerror();
		isitgood(map[cnt2]);
		cnt2++;
	}
	isitones(map[cnt2 - 1]);
	isitcomplete(map);
}

void	isitcomplete(char **str)
{
	int	cnt;
	int	p;
	int	zero;
	int	e;
	int	c;

	p = 0;
	zero = 0;
	e = 0;
	c = 0;
	while (*str != NULL)
	{
		cnt = 0;
		while ((*str)[cnt] != '\0')
		{
			p = (((*str)[cnt] == 'P') + p);
			zero = (((*str)[cnt] == '0') + zero);
			e = (((*str)[cnt] == 'E') + e);
			c = (((*str)[cnt] == 'C') + c);
		cnt ++;
		}
	str++;
	}
	if (p != 1 || e != 1 || c == 0)
		itsanerror();
}
