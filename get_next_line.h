/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:08:37 by chanhhon          #+#    #+#             */
/*   Updated: 2024/01/07 12:31:11 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	gnl_input_list(t_list **list, int fd);
void	gnl_append(t_list **list, char *buf);
void	gnl_list_to_str(char *str, t_list **list);
void	gnl_update_list(t_list **list);
size_t	ft_strchr_modified(const char *s, int c);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	list_to_str_util(char *str, t_list **list);
#endif
