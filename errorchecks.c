/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errorchecks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 12:48:08 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/01 14:30:55 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**errorchecks(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		itsanerror();
	isitber(argv[1]);
	fd = isitexistant(argv[1]);
	return (makeamap(fd));
}

int	isitexistant(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd <= 2)
		itsanerror();
	return (fd);
}

void	isitones(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] != '1')
			itsanerror();
		cnt++;
	}
}

void	isitgood(char *str)
{
	int	cnt;

	cnt = 0;
	if (str[0] != '1')
		itsanerror();
	while (str[cnt] != '\0')
	{
		if (!(str[cnt] == '1' || str[cnt] == '0' || str[cnt] == 'P'
				|| str[cnt] == 'E' || str[cnt] == 'C'))
			itsanerror();
		cnt++;
	}
	if (str[cnt - 1] != '1')
		itsanerror();
}

void	isitber(char *argv)
{
	int	cnt;

	if (argv == NULL)
		itsanerror();
	cnt = ft_strlen(argv);
	if (cnt < 4)
		itsanerror();
	if (!(argv[cnt - 1] == 'r' && argv[cnt - 2] == 'e' && argv[cnt - 3] == 'b'
			&& argv[cnt - 4] == '.'))
		itsanerror();
}
