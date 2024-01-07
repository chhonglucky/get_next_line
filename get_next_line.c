/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:51:26 by chanhhon          #+#    #+#             */
/*   Updated: 2024/01/07 12:36:31 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*read_text;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &read_text, 0) < 0)
		return (NULL);
	gnl_input_list(&list, fd);
	if (list == NULL)
		return (NULL);
	gnl_list_to_str(read_text, &list);
	gnl_update_list(&list);
	return (read_text);
}

void	gnl_input_list(t_list **list, int fd)
{
	int		char_cnt;
	char	*buf;

	while (!ft_strchr_modified(buf, '\n'))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_cnt = read(fd, buf, BUFFER_SIZE);
		if (!char_cnt)
		{
			free (buf);
			return ;
		}
		buf[char_cnt] = '\0';
		gnl_append(list, buf);
	}
}

void	gnl_append(t_list **list, char *buf)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	if (ft_lstlast(*list) == NULL)
		*list = node;
	else
		ft_lstlast(*list)->next = node;
		node->content = buf;
		node->next = NULL;
}

void	gnl_list_to_str(char *str, t_list **list)
{
	int	strlen;
	int	i;

	if (list == NULL)
		return ;
	strlen = 0;
	while (list)
	{
		i = 0;
		while ((*list)->content[i])
		{
			strlen++;
			if ((*list)->content[i] == '\n')
				break ;
			i++;
		}
		(*list) = (*list)->next;
	}
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return ;
	list_to_str_util(str, list);
}

void	gnl_update_list(t_list **list)
{
	int		i;
	int		k;
	char	*buf;
	t_list	*clean_node;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	i = 0;
	k = 0;
	while (ft_lstlast(*list)->content[i]
		&& ft_lstlast(*list)->content[i] != '\n')
		++i;
	while (ft_lstlast(*list)->content[i] && ft_lstlast(*list)->content[++i])
		buf[k++] = ft_lstlast(*list)->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}
