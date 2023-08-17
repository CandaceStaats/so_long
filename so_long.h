/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 11:59:38 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 15:12:44 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# define GRID_SIZE 32
# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

size_t			ft_strlen(char const *str);
void			ft_bzero(void *s, size_t n);
int				ft_isnewline(char *s);
char			*ft_linetransfer(char **line, char *leftover);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
int				ft_iswhat(char *s, int check);
void			itsanerror(void);
void			isitber(char *argv);
int				isitexistant(char *argv);
char			**errorchecks(int argc, char **argv);
char			**makeamap(int fd);
char			**allocatemap(char **oldmap, int cnt);
void			isitcomplete(char **str);
void			isitvalid(char **map);
void			isitgood(char *str);
void			isitones(char *str);
void			*ft_memset(void *b, int c, size_t len);
typedef struct s_images
{
	mlx_texture_t	*player;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*ground;
}	t_images;
t_images		load_images(void);
void			putimage(mlx_texture_t	*pic, int x, int y, mlx_image_t *img);
mlx_texture_t	*assignimage(t_images images, char map);
void			draw_map(char **map, mlx_image_t *img,
					t_images images);
int				getwidth(char **map);
int				getheight(char **map);
void			directions(mlx_key_data_t keydata, void *param);
char			keystrokes(char **map, mlx_key_data_t keydata);
typedef struct s_redraw
{
	t_images	images;
	char		**map;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_redraw;
char			whereami(char **map, int x, int y);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nitems, size_t size);
void			validpath(char **map);
char			addp(char **map);
int				placingp(char **map, int x, int y);
#endif
