/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:59:45 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/12 21:08:35 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_alt(char *s1, char *s2)
{
	char	*s;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s)
	{
		free(s1);
		return (NULL);
	}
	s[0] = '\0';
	ft_strlcpy(s, s1, len_s1 + 1);
	ft_strlcpy(s + len_s1, s2, len_s2 + 1);
	free(s1);
	return (s);
}

static char	*ft_first_line(char buffer[BUFFER_SIZE + 1], char *buffer_stor)
{
	char	*line;
	char	*start_new_line;
	int		i;

	line = NULL;
	start_new_line = ft_strchr(buffer, '\n') + 1;
	i = 0;
	while (buffer_stor[i] != '\n')
		i++;
	line = ft_substr(buffer_stor, 0, i + 1);
	free(buffer_stor);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(buffer, start_new_line, ft_strlen(start_new_line) + 1);
	return (line);
}

static char	*check_bytes_read(ssize_t bytes_read, char *buffer_stor)
{
	if (bytes_read == 0)
	{
		if (buffer_stor[0] == '\0')
		{
			free(buffer_stor);
			return (NULL);
		}
		return (buffer_stor);
	}
	free(buffer_stor);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*buffer_stor;
	ssize_t		bytes_read;

	buffer_stor = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buffer_stor = ft_strjoin_alt(buffer_stor, buffer);
		if (buffer_stor == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			return (ft_first_line(buffer, buffer_stor));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			buffer[0] = '\0';
		else
			buffer[bytes_read] = '\0';
		if (bytes_read <= 0)
			return (check_bytes_read(bytes_read, buffer_stor));
	}
}
/*
# include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*str;
	fd = open("giant_line.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Erreur d'ouverture\n", 19);
		return (1);
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("line: %s\n", str);
		free(str);
		str = get_next_line(fd);
		if (!str)
			printf("EOF\n");
	}
	close(fd);
	return (0);
} */
