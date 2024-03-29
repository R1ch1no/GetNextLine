/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:03:59 by rkurnava          #+#    #+#             */
/*   Updated: 2022/12/04 18:07:31 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_hold(char *hold, int fd)
{
	char	*grab;
	int		status;

	status = 26;
	grab = malloc(BUFFER_SIZE + 1);
	if (!grab)
		return (NULL);
	while (ft_newline(hold) == 0 && status > 0)
	{
		status = read(fd, grab, BUFFER_SIZE);
		if (status == -1)
		{
			free(grab);
			free(hold);
			return (NULL);
		}
		grab[status] = '\0';
		if (status > 0)
			hold = ft_strjoin(hold, grab);
	}
	free(grab);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold[fd] = ft_hold(hold[fd], fd);
	line = ft_strtrim(hold[fd], '\n');
	hold[fd] = ft_strtrim_hold(hold[fd], '\n');
	return (line);
}
