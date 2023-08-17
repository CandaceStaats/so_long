/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilscont.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:20:31 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 13:57:13 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cnt;

	cnt = (unsigned char *)b;
	while (len)
	{
		*cnt = (unsigned char)c;
		cnt++;
		len--;
	}
	return (b);
}

int	getwidth(char **map)
{
	return (ft_strlen(*map) * GRID_SIZE);
}

int	getheight(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height * GRID_SIZE);
}

void	directions(mlx_key_data_t keydata, void *param)
{
	char				store;
	t_redraw			*redraw;
	static int			cnt = 0;
	char				*cntstr;
	static mlx_image_t	*textimage = NULL;

	redraw = (t_redraw *)param;
	store = keystrokes(redraw->map, keydata);
	if (store == 'E')
	{
		cnt++;
		write (1, "Winner!\n", 9);
		exit(EXIT_SUCCESS);
	}
	if (store != '1' && store != '\0')
		cnt++;
	cntstr = ft_itoa(cnt);
	draw_map(redraw->map, redraw->img, redraw->images);
	mlx_delete_image(redraw->mlx, textimage);
	textimage = mlx_put_string(redraw->mlx, cntstr, 110, 0);
	free(cntstr);
}

char	whereami(char **map, int x, int y)
{
	int		playerx;
	int		playery;
	char	r;

	playery = 0;
	while (map[playery] != NULL)
	{
		playerx = 0;
		while (map[playery][playerx] != '\0')
		{
			if (map[playery][playerx] == 'P')
			{
			r = map[playery + y][playerx + x];
				if (r != '1')
				{
					map[playery + y][playerx + x] = 'P';
					map[playery][playerx] = '0';
					return (r);
				}
			}
		playerx++;
		}
	playery++;
	}
	return ('1');
}
