/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:28:31 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/12 14:51:10 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	char	*content;
	t_node	*next;
}	t_node;

// int	ft_lstsize(t_node *node);
void	ft_lstdelone(t_node *node, void (*del)(void *));
t_node	*ft_lstnew(void *content);
t_node	*ft_lstlast(t_node *node);
void	ft_lstadd_back(t_node **head, t_node *new);

size_t	ft_strlen(const char *s);
int		ft_strchr_sp(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

ssize_t	fill_stash(int fd, t_node **stash);
char	*extract_line(t_node **stash, int nl_pos);
void	clean_stash(t_node **stash, int nl_pos);
char	*get_next_line(int fd);

#endif