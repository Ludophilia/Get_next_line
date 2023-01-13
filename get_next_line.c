/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/13 21:42:31 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

ssize_t	fill_stash(int fd, t_node **stash)
{
	t_node		*new_node;
	ssize_t		bytesread;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	// printf("buffer -> '%s'\n", buffer);
	if (bytesread > 0)
	{
		new_node = ft_lstnew(buffer); // if ft_lstnew is used only once, 
		// create node here...
		if (!new_node)
		{
			free(buffer);
			return (-1);
		}
		ft_lstadd_back(stash, new_node); // And if there is a problem ? Segfault.
	}
	else
		free(buffer);
	return (bytesread);
}

void	clean_stash(t_node **stash)
{
	char	*new_content;
	t_node	*next;
	int		nl_pos;
	int		i;

	nl_pos = -1;
	// if (!*stash)
	// 	printf("Cleaning Start: No first node content\n");
	// else
	// 	printf("Cleaning Start: First node content: '%s'\n", (*stash)->content);
	// What happens when there is no newline ?
	while (*stash && nl_pos == -1)
	{
		next = (*stash)->next;
		nl_pos = ft_strchr_sp((*stash)->content, '\n');
		if (nl_pos != -1)
			break ;
		free((*stash)->content);
		free((*stash));
		*stash = next;
		if (!next && nl_pos == -1)
			return ;
	}
	new_content = ft_calloc(ft_strlen((*stash)->content) - nl_pos + 1,
		sizeof(char));
	if (!new_content)
		return ; // Is that enough?
	i = 0;
	nl_pos += 1;
	while (((*stash)->content)[nl_pos])
		new_content[i++] = ((*stash)->content)[nl_pos++];
	free((*stash)->content);
	(*stash)->content = new_content;
}

size_t	content_len(t_node *node)
{
	size_t	count;
	int 	nl_pos;

	// Count the total length of str
	count = 0;
	while (node)
	{
		nl_pos = ft_strchr_sp(node->content, '\n');
		if (node->next || (nl_pos == -1))
			count += ft_strlen(node->content); // Useful ? Optimization later.
		else
			count += nl_pos + 1;
		node = node->next;
	}
	return (count);
}

char	*extract_line(t_node *node)
{
	char	*line;
	int		i;
	char	*content;
	size_t	count;

	// Build the line and fill it
	count = content_len(node);
	line = ft_calloc(count + 1, sizeof(char));
	if (!line)
		return ((char *)0);
	i = 0;
	while (node)
	{
		content = node->content;
		while (*content && count--)
			line[i++] = *content++;
		node = node->next;
	}
	return (line);
}

// The challenge of multiple fd is to have a different stash for each of them
char	*get_next_line(int fd)
{
	static t_node	**stash;
	int				nl_pos;
	ssize_t			bytesread;
	char			*line;

	if (!stash)
		stash = ft_calloc(1, sizeof(t_node *));
	// if (!*stash)
	// 	printf("Start: No first node content\n");
	// else
	// 	printf("Start: First node content: '%s'\n", (*stash)->content);
	if (stash)
	{
		bytesread = fill_stash(fd, stash);
		// printf("bytesread (do) -> %li\n", bytesread);
		if (bytesread == 0 && !*stash)
		{
			free(stash);
			stash = (t_node **)0;
			return ((char *)0);
		}
		nl_pos = -1;
		while (bytesread > 0 && nl_pos == -1)
		{
			bytesread = fill_stash(fd, stash);
			// printf("bytesread (while) -> %li\n", bytesread);
			// printf("firstnode content: '%s'\n", (*stash)->content);
			// printf("lastnode content: '%s'\n\n", ft_lstlast(*stash)->content);
			nl_pos = ft_strchr_sp(ft_lstlast(*stash)->content, '\n');
		}	
		if (bytesread == -1)
			return ((char *)0);
		line = extract_line(*stash);
		clean_stash(stash);
		// printf("End: First node content: '%s'\n", (*stash)->content);
		return (line);
	}
	return ((char *)0);
}
