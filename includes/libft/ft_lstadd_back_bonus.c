/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:20 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 14:43:27 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next_node;

	next_node = *lst;
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (next_node -> next)
		next_node = next_node -> next;
	next_node -> next = new;
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*node0 = (void *) 0;
	t_list	*node1;
	t_list	*node2;
	char	fruta[] = "ABACAXI";
	char	bolo[] = "BOLO";

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));

	node1 -> content = &bolo;
	node1 -> next = NULL;
	node2 -> content =  &fruta;
	node2 -> next = NULL;
	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node0, node2);
	printf("%s de %s\n",(char *) node0 -> content,(char *) 
		node0 -> next -> content);
	ft_lstadd_back(&node0, NULL);
	free(node1);
	free(node2);
	return (0);
}*/
