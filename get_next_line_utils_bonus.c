/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/15 18:46:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_sp(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*arr;
	int			i;

	total = nmemb * size;
	if ((size != 0) && (nmemb != (total / size)))
		return (0);
	arr = malloc(total);
	if (!arr)
		return (0);
	i = 0;
	while (total--)
		((char *)arr)[i++] = '\x0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	slen;
	size_t	i;

	if (s == 0)
		return (0);
	size = 0;
	slen = ft_strlen(s);
	while (((start + size) < slen) && (size < len))
		size++;
	substr = ft_calloc(size + 1, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while ((i < size) && ((start + i) < slen))
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

char	**write_stash(char **stash, int fd, ssize_t bytesread, char *buffer)
{
	char	*old_stash;
	char	*new_stash;
	size_t	size;
	size_t	i;

	old_stash = stash[fd];
	size = bytesread;
	if (old_stash)
		size += ft_strlen(old_stash);
	new_stash = ft_calloc(size + 1, sizeof(char));
	if (!new_stash)
		return (0);
	i = 0;
	if (old_stash)
		while (i < (size - bytesread))
			new_stash[i++] = *old_stash++;
	while (i < size)
		new_stash[i++] = *buffer++;
	if (stash[fd])
		free(stash[fd]);
	stash[fd] = new_stash;
	return (stash);
}
