/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:06:15 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:06:16 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;
	void	*value;

	value = content;
	node = ft_calloc(1, sizeof(t_list));
	if (node == NULL)
		return (node);
	node->content = value;
	node->next = NULL;
	return (node);
}
