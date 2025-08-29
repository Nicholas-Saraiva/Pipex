/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:25:57 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/17 09:55:16 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*t_node;
	void	*func_del;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	while (lst)
	{
		func_del = f(lst -> content);
		t_node = ft_lstnew(func_del);
		if (!t_node)
		{
			del(func_del);
			ft_lstclear(&node, del);
			return (NULL);
		}
		lst = lst -> next;
		ft_lstadd_back(&node, t_node);
	}
	return (node);
}

/*#include <string.h>

void	*my_len(void *lst)
{
	return (void *)strlen(lst);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	char	*a;

	a = malloc(1);
	*a = 'A';
	node1 = ft_lstnew(a);
	node2 = ft_lstmap(node1, my_len, NULL);
	free(node2);
	free(node1);
}*/

/*include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	void	*test;

	if (!lst)
		return (NULL);
	//test = f(lst -> content)
	//node = ft_lstnew(test);
	//t_node = node;
	//if (!node)
	//	ft_lstdelone(t_node, del);
	//lst = lst -> next;
	res = ft_lstnew(lst->content);
	res->next = lst->next;
	while (res)
	{
		test = f(lst -> content);
		if (!test)
		{
			ft_lstdelone(res, del);
			break ;
		}
		res -> content = test;
		res = lst->next;
	}
	return (res);
}*/
