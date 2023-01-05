/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/05 14:44:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*arr;
	void		*head;

	total = nmemb * size;
	if ((size != 0) && (nmemb != (total / size)))
		return ((void *)0);
	arr = malloc(total);
	head = arr;
	if (arr)
		while (total--)
			*(char *)head++ = '\x0';
	return (arr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	dpos;
	size_t	spos;

	dpos = 0;
	while (size && dst[dpos])
	{
		dpos++;
		size--;
	}
	dsize = dpos;
	spos = 0;
	while (src[spos])
	{
		if (size > 1)
		{
			dst[dpos] = src[spos];
			dpos++;
			size--;
		}
		spos++;
	}
	if (size)
		dst[dpos] = '\x0';
	return (dsize + spos);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	size_t		ls1;
	size_t		ls2;
	size_t		i;

	if (s1 == (char *)0 || s2 == (char *)0)
		return ((char *)0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	dest = ft_calloc(ls1 + ls2 + 1, sizeof(char));
	if (dest)
	{
		i = ft_strlcat(dest, s1, (ls1 + 1));
		if (i == (0 + ls1))
			i = ft_strlcat(dest, s2, (ls1 + ls2 + 1));
		if (i == (ls1 + ls2))
			return (dest);
	}
	return ((char *)0);
}
