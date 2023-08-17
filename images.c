/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 12:47:46 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 15:43:04 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char **map, mlx_image_t *img, t_images images)
{
	int				x;
	int				y;
	mlx_texture_t	*pic;

	y = 0;
	while (map[y] != NULL)
	{
	x = 0;
		while (map[y][x] != '\0')
		{
			pic = assignimage(images, map[y][x]);
			putimage(pic, x, y, img);
			x++;
		}
	y++;
	}
}

t_images	load_images(void)
{
	t_images	images;

	images.ground = mlx_load_png("./beach.png");
	images.wall = mlx_load_png("./ocean.png");
	images.player = mlx_load_png("./penguin.png");
	images.collectible = mlx_load_png("./fish.png");
	images.exit = mlx_load_png("./tinypenguinhouse.png");
	if (!images.ground || !images.wall || !images.player || !images.exit
		|| !images.collectible)
		exit(EXIT_FAILURE);
	return (images);
}

mlx_texture_t	*assignimage(t_images images, char map)
{
	if (map == 'P')
		return (images.player);
	if (map == 'C')
		return (images.collectible);
	if (map == '1')
		return (images.wall);
	if (map == '0')
		return (images.ground);
	if (map == 'E')
		return (images.exit);
	return (NULL);
}

void	putimage(mlx_texture_t	*pic, int x, int y, mlx_image_t *img)
{
	mlx_draw_texture(img, pic, x * GRID_SIZE, y * GRID_SIZE);
}
