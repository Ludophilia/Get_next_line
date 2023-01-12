/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/12 23:38:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fill_stash(int fd, t_node **stash)
{
	t_node		*new_node;
	ssize_t		bytesread;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread > 0)
	{
		new_node = ft_lstnew(buffer); // if ft_lstnew is used only once, create node here...
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

void	clean_stash(t_node **stash, int nl_pos)
{
	// How to clean the stash ???
	// What to do to clean the stash ??
		// - Iterate on the nodes
		// - If a node doesn't contain '\n', destroy and... move head
		// to the next node
		// - If the node contains '\n', create a substring from node's content,
		// free the old content add the new one at his place
	t_node	*next;
	// int		nl_pos;
	char	*new_content;
	char	*nc_pos;

	while (*stash)
	{
		next = (*stash)->next;
		nl_pos = ft_strchr_sp((*stash)->content, '\n');
		if (nl_pos == -1)
		{
			free((*stash)->content);
			free((*stash));
		}
		else
		{
			new_content = ft_calloc(ft_strlen((*stash)->content) - nl_pos + 1,
				sizeof(char));
			if (new_content)
			{
				nc_pos = new_content;
				while (((*stash)->content)[nl_pos])
					*nc_pos++ = ((*stash)->content)[nl_pos++];
				free((*stash)->content);
				(*stash)->content = new_content;
				break ; // useless
			}
			// no return ?
		}
		*stash = next;
	}
}

char	*extract_line(t_node **stash, int nl_pos)
{
	char	*line;
	char	*linepos;
	t_node	*node;
	char	*content;
	size_t	count;

	node = *stash;
	count = 0;
	while (node)
	{
		if (node->next || (nl_pos == -1))
			count += ft_strlen(node->content); // Useful ? Optimization later.
		else
			count += nl_pos + 1;
		node = node->next;
	}
	line = ft_calloc(count + 1, sizeof(char));
	if (!line)
		return ((char *)0);
	node = *stash;
	linepos = line;
	while (node)
	{
		content = node->content;
		while (*content && count--)
			*linepos++ = *content++;
		node = node->next;
	}
	clean_stash(stash, nl_pos);
	return (line);
}

// The challenge of multiple fd is to have a different stash for each of them
char	*get_next_line(int fd)
{
	static t_node	**stash;
	int				nl_pos;
	ssize_t			bytesread;

	if (!stash)
		stash = ft_calloc(1, sizeof(t_node *));
	if (stash)
	{
		bytesread = fill_stash(fd, stash);
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
			nl_pos = ft_strchr_sp(ft_lstlast(*stash)->content, '\n');
		}	
		if (bytesread == -1)
			return ((char *)0);

		return (extract_line(stash, nl_pos));
	}
	return ((char *)0);
}
