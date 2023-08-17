/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 11:50:10 by candace       #+#    #+#                 */
/*   Updated: 2022/10/31 15:11:56 by cstaats       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	cnt;
	char			*substr;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (cnt < len && s[cnt + start] != '\0')
	{
		substr[cnt] = s[cnt + start];
		cnt++;
	}
	substr[cnt] = '\0';
	return (substr);
}

size_t	ft_strlen(char const *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_linetransfer(char **line, char *leftover)
{
	size_t	extra;
	char	*tplftovr;

	extra = 0;
	while (leftover[extra] != '\n' && leftover[extra] != '\0')
	{
		extra++;
	}
	*line = ft_substr(leftover, 0, extra);
	tplftovr = ft_substr(leftover, extra + 1, ft_strlen(leftover) - extra);
	free(leftover);
	return (tplftovr);
}

int	ft_isnewline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*leftover = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			readreturn;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ft_iswhat(leftover, -1));
	readreturn = 1;
	while (readreturn > 0 && ft_isnewline(leftover) == 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		readreturn = read(fd, buf, BUFFER_SIZE);
		if (readreturn < 0)
			return (ft_iswhat(leftover, -1));
		if (leftover == NULL)
			leftover = ft_strdup(buf);
		else
			leftover = ft_strjoin(leftover, buf);
		if (leftover == NULL)
			return (-1);
	}
	if (leftover != NULL)
		leftover = ft_linetransfer(line, leftover);
	if (readreturn == 0)
		return (ft_iswhat(leftover, 0));
	return (1);
}
