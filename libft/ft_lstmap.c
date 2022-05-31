/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:06:11 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:06:12 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (head);
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp)
			ft_lstadd_back(&head, temp);
		else
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
