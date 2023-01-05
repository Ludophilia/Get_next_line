/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/05 14:48:51 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] && s)
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

ssize_t	fill_stash(int fd, char	**stash)
{
	char		*old_stash;
	ssize_t		bytesread;
	char		*buffer;

	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer || !*stash)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1)
		return (-1);
	old_stash = *stash;
	*stash = ft_strjoin(old_stash, buffer);
	free(old_stash);
	free(buffer);
	return (bytesread);
}

// should work without BUFFER_SIZE size, maybe with an ifndef
// Use read (WITH constant macro BUFFER_SIZE), malloc, free. static vars can 
// help.

// return the line from fd (with a \n if it contains one) as a char *
// Repeated calls to your gnl should let you read the fd one line at a time
// or NULL/(char *)0 in case of error.

char	*get_next_line(int fd)
{
	static char		*stash;
	ssize_t			bytesread;

	int				sep;
	char			*line;
	
	if (!stash)
		stash = calloc(BUFFER_SIZE + 1, sizeof(char));
	bytesread = fill_stash(fd, &stash);
	if (bytesread == -1)
		return ((char *)0);
	while (bytesread > 0 && ft_strchr(stash, '\n') == -1)
	{
		bytesread = fill_stash(fd, &stash);
		if (bytesread == -1)
			return ((char *)0);
	}
	// Now, how this part should reacts when bytesread == 0 initially?
	sep = ft_strchr(stash, '\n');
	if (sep != -1)
	{
		char *old_stash = stash; // pattern here
		line = ft_substr(old_stash, 0, sep + 1);
		stash = ft_substr(old_stash, sep + 1, ft_strlen(old_stash) - (sep + 1));
		free(old_stash);
	}
	else
		line = stash;
	// printf("\tstash -> '%s'\n", stash);
	// Is the stash will ever be released ?
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("tests/test_file0.txt", O_RDONLY);
	// printf("\tfd -> %i\n", fd);
	printf("\tGNL -> '%s'\n", get_next_line(fd));
	printf("\tGNL -> '%s'\n", get_next_line(fd));

	printf("\tGNL -> '%s'\n", get_next_line(fd));
	// printf("\tGNL -> '%s'\n", get_next_line(fd));
	close(fd);
}