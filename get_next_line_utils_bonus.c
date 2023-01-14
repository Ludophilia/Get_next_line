/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/14 15:20:15 by jgermany         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	ls1;
	size_t	ls2;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	dest = ft_calloc(ls1 + ls2 + 1, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < ls1)
		dest[i++] = *s1++;
	while (i < (ls1 + ls2))
		dest[i++] = *s2++;
	return (dest);
}
