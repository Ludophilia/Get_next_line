/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:16:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/11 22:52:13 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstsize(t_node *node)
{
	int	size;

	size = 0;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

void	ft_lstdelone(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	if (del)
		del(node->content);
	free(node);
}



t_node	*ft_lstnew(void *content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ((t_node *)0);
	node->content = content;
	node->next = (t_node *)0;
	return (node);
}

t_node	*ft_lstlast(t_node *node)
{
	while (node)
	{
		if (!node->next)
			return (node);
		node = node->next;
	}
	return ((t_node *)0);
}

void	ft_lstadd_back(t_node **head, t_node *new)
{
	t_node	*last;

	if (!head)
		return ;
	last = ft_lstlast(*head);
	if (last)
		last->next = new;
	else
		*head = new;
}




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

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t	ls1;
// 	size_t	ls2;
// 	size_t	i;

// 	if (s1 == (char *)0 || s2 == (char *)0)
// 		return ((char *)0);
// 	ls1 = ft_strlen(s1);
// 	ls2 = ft_strlen(s2);
// 	dest = malloc((ls1 + ls2 + 1) * sizeof(char));
// 	if (!dest)
// 		return ((char *)0);
// 	i = 0;
// 	while (i < ls1)
// 		dest[i++] = *s1++;
// 	while (i < (ls1 + ls2))
// 		dest[i++] = *s2++;
// 	dest[i] = '\x0';
// 	return (dest);
// }
