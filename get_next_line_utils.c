/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:51:29 by chanhhon          #+#    #+#             */
/*   Updated: 2024/01/07 12:37:18 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr_modified(const char *s, int c)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)s;
	while (len < ft_strlen(str))
	{
		if (str[len] == (char)c)
			return (len);
		len++;
	}
	if ((char)c == '\0')
		return (len);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (lst)
		while (temp->next)
			temp = temp->next;
	return (temp);
}

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

void	list_to_str_util(char *str, t_list **list)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while ((*list)->content[i])
		{
			if ((*list)->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = (*list)->content[i++];
		}
		(*list) = (*list)->next;
	}
	str[k] = '\0';
}
