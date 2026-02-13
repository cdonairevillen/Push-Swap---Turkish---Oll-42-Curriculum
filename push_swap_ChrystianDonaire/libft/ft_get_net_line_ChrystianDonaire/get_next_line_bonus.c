/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdonaire <cdonaire@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:50:59 by cdonaire          #+#    #+#             */
/*   Updated: 2025/10/20 16:51:08 by cdonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_build_new_line(char **text)
{
	size_t	i;
	char	*line;
	char	*rest;

	if (!text || !*text)
		return (NULL);
	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	if ((*text)[i] == '\n')
		i++;
	line = ft_substr(*text, 0, i);
	if (!line)
		return (free(*text), *text = NULL, NULL);
	rest = ft_substr(*text, i, ft_strlen(*text) - i);
	free(*text);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		*text = NULL;
	}
	else
		*text = rest;
	return (line);
}

static char	*ft_buffer_new_line(char *text, char *buff, int fd)
{
	ssize_t	bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0 && !ft_strchr(text, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(text), NULL);
		if (bytes == 0)
			break ;
		buff[bytes] = '\0';
		temp = text;
		text = ft_strjoin(temp, buff);
		free(temp);
		if (!text)
			return (free(buff), NULL);
	}
	free(buff);
	return (text);
}

static char	*ft_get_new_line(char *text, int fd)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(text), NULL);
	if (!text)
		text = ft_strdup("");
	if (!text)
		return (free(buff), NULL);
	text = ft_buffer_new_line(text, buff, fd);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*text[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = ft_get_new_line(text[fd], fd);
	if (!text[fd] || ft_strlen(text[fd]) == 0)
	{
		if (text[fd])
		{
			free(text[fd]);
			text[fd] = NULL;
		}
		return (NULL);
	}
	output = ft_build_new_line(&text[fd]);
	return (output);
}
