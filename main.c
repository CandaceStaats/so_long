/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 12:48:53 by candace       #+#    #+#                 */
/*   Updated: 2022/11/09 11:39:31 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_redraw	redraw;

	redraw.map = errorchecks(argc, argv);
	redraw.mlx = mlx_init(getwidth(redraw.map),
			getheight(redraw.map), "Penguin Power", false);
	if (!redraw.mlx)
		write(1, "mlx_init returned NULL\n", 24);
	redraw.img = mlx_new_image(redraw.mlx, getwidth(redraw.map),
			getheight(redraw.map));
	if (!redraw.img)
		exit(EXIT_FAILURE);
	ft_memset(redraw.img->pixels, 255, sizeof(int32_t)
		* getwidth(redraw.map) * getheight(redraw.map));
	redraw.images = load_images();
	draw_map(redraw.map, redraw.img, redraw.images);
	mlx_image_to_window(redraw.mlx, redraw.img, 0, 0);
	mlx_key_hook (redraw.mlx, directions, &redraw);
	mlx_put_string(redraw.mlx, "Move Count:", 0, 0);
	mlx_loop(redraw.mlx);
	mlx_terminate(redraw.mlx);
	return (EXIT_SUCCESS);
}
