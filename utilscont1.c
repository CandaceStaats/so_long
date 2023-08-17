/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilscont1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <cstaats@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 12:40:44 by cstaats       #+#    #+#                 */
/*   Updated: 2022/11/08 13:38:50 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	keystrokes(char **map, mlx_key_data_t keydata)
{
	char	store;

	if (keydata.action != MLX_PRESS)
		return ('\0');
	if (keydata.key == MLX_KEY_UP)
		store = whereami(map, 0, -1);
	if (keydata.key == MLX_KEY_DOWN)
		store = whereami(map, 0, 1);
	if (keydata.key == MLX_KEY_LEFT)
		store = whereami(map, -1, 0);
	if (keydata.key == MLX_KEY_RIGHT)
		store = whereami(map, 1, 0);
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	return (store);
}

static int	ft_mem(long int store)
{
	int	len;

	len = 0;
	if (store == 0)
		len = 1;
	else if (store < 0)
	{
		len = 1;
		store = -store;
	}
	while (store)
	{
		store /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_mem(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		exit(EXIT_FAILURE);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	str[len - 1] = n % 10 + '0';
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pnt;

	pnt = malloc(nitems * size);
	if (pnt == NULL)
		return (NULL);
	ft_bzero(pnt, (nitems * size));
	return (pnt);
}
