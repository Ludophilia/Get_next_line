/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/08 18:53:15 by jgermany         ###   ########.fr       */
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

int	ft_strchr_sp(const char *s, int c)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	ls1;
	size_t	ls2;
	size_t	i;

	if (s1 == (char *)0 || s2 == (char *)0)
		return ((char *)0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	dest = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!dest)
		return ((char *)0);
	i = 0;
	while (i < ls1)
		dest[i++] = *s1++;
	while (i < (ls1 + ls2))
		dest[i++] = *s2++;
	dest[i] = '\x0';
	return (dest);
}
