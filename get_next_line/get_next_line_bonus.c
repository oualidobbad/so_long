/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokali <dokali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:41:33 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/20 17:01:28 by dokali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:52:34 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/19 14:19:12 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*renew_saved(char *saved)
{
	size_t	i;
	size_t	j;
	char	*new_saved;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	new_saved = malloc((ft_strlen(saved) - i + 1) * sizeof(char));
	if (!new_saved)
		return (NULL);
	j = 0;
	i++;
	while (saved[i])
		new_saved[j++] = saved[i++];
	new_saved[j] = '\0';
	free(saved);
	return (new_saved);
}

char	*cut_line(char *saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *saved)
{
	int		read_byte;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0 && find_line(saved) == -1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved[1023];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	saved[fd] = read_buffer(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = cut_line(saved[fd]);
	saved[fd] = renew_saved(saved[fd]);
	return (line);
}
// int	main(void)
// {
// 	int		fd, fd1;
// 	char	*line, *line2;

// 	fd = open("tx.txt", O_RDONLY);
// 	fd1 = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	line2= get_next_line(fd1);
// 	printf("line1: %s", line);
// 	printf("line2: %s", line2);
// 	free(line2);
// 	free(line);
// 	line = get_next_line(fd);
// 	line2= get_next_line(fd1);
// 	printf("=================\n");
// 	printf("line1: %s", line);
// 	printf("line2: %s", line2);
// 	free(line2);
// 	free(line);
// }
