/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/04 19:28:57 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] && s)
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	slen;
	size_t	i;

	if (s == (char *)0)
		return ((char *)0);
	size = 0;
	slen = ft_strlen(s);
	while (((start + size) < slen) && (size < len))
		size++;
	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return ((char *)0);
	i = 0;
	while ((i < size) && ((start + i) < slen))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\x0';
	return (substr);
}

#include <stdio.h>

// should work without BUFFER_SIZE size, maybe with an ifndef
// Use read (WITH constant macro BUFFER_SIZE), malloc, free. static vars can 
// help.

// return the line from fd (with a \n if it contains one) as a char *
// Repeated calls to your gnl should let you read the fd one line at a time
// or NULL/(char *)0 in case of error.

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*tmp_stash;
	char			*buffer;
	ssize_t			bytesread;

	int				sep;
	char			*line;
	
	// Now, what to do when there is no bytes to read ?
		// good question (see below in main)

	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (!stash)
		stash = calloc(1, sizeof(char));
	if (bytesread == -1 || !buffer || !stash)
		return ((char *)0);
	while (bytesread > 0 && ft_strchr(buffer, '\n') == -1)
	{
		tmp_stash = stash; // pattern here
		stash = ft_strjoin(tmp_stash, buffer);
		free(tmp_stash);
		ft_bzero(buffer, BUFFER_SIZE);
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	tmp_stash = stash; // pattern here
	stash = ft_strjoin(tmp_stash, buffer);
	free(tmp_stash);
	sep = ft_strchr(stash, '\n');
	// printf("sep -> %i\n", sep);
	if (sep != -1)
	{
		tmp_stash = stash; // pattern here
		line = ft_substr(tmp_stash, 0, sep + 1);
		stash = ft_substr(tmp_stash, sep + 1, ft_strlen(tmp_stash) - (sep + 1));
		free(tmp_stash);
	}
	else
		line = stash;
	// printf("\tstash -> '%s'\n", stash);
	free(buffer);
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
	printf("\tGNL -> '%s'\n", get_next_line(fd));
	close(fd);
}