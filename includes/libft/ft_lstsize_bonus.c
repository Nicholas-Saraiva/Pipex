/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:35:55 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 14:39:05 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_nodes;

	n_nodes = 0;
	while (lst)
	{
		n_nodes++;
		lst = lst -> next;
	}
	return (n_nodes);
}

/*#include <stdio.h>
int	main(void)
{
	t_list **ptr_node;
	t_list	*node1;
	t_list	*node2;
	char	fruta[] = "ABACAXI";
	char	bolo[] = "BOLO";
	int		i = 2;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	ptr_node = malloc(sizeof(t_list *) * 2);

	(*ptr_node) = node1;
	node1 -> content = &fruta;
	node1 -> next = NULL;
	node2 -> content =  &bolo;
	node2 -> next = NULL;
	ft_lstadd_front(ptr_node, node2);
	printf("%d", ft_lstsize(*ptr_node));
	free(node1);
	free(node2);
	free(ptr_node);
}*/
