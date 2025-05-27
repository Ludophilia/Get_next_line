/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:04:21 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/27 14:20:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_strlen(const char *s)
{
	long	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

long	get_char_pos(const char *s, int c)
{
	long	len;
	long	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	long	size;
	char	*dupl;
	int		i;

	size = ft_strlen(s);
	dupl = malloc((size + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	dupl[size] = 0;
	i = -1;
	while (s[++i])
		dupl[i] = s[i];
	return (dupl);
}

char	*ft_substr(char const *s, unsigned int start, long len)
{
	char	*sub;
	long	slen;
	long	sublen;
	long	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	sublen = 0;
	while (start + sublen < slen && sublen < len)
		++sublen;
	sub = malloc((sublen + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[sublen] = 0;
	i = 0;
	while (i < sublen)
	{
		sub[i] = s[start + i];
		++i;
	}
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	len[2];
	char	*s1s2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	s1s2 = malloc((len[0] + len[1] + 1) * sizeof(char));
	if (s1s2 == NULL)
		return (NULL);
	s1s2[len[0] + len[1]] = 0;
	i = 0;
	while (s1[i])
	{
		s1s2[i] = s1[i];
		++i;
	}
	while (s2[i - len[0]])
	{
		s1s2[i] = s2[i - len[0]];
		++i;
	}
	return (s1s2);
}
