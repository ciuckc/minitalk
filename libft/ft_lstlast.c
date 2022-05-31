/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scristia <scristia@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:06:05 by scristia      #+#    #+#                 */
/*   Updated: 2021/12/17 17:06:06 by scristia      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int			i;
	t_list		*temp;

	temp = lst;
	i = ft_lstsize(lst);
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	return (temp);
}
