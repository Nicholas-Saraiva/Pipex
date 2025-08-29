/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaraiva <nsaraiva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:43:38 by nsaraiva          #+#    #+#             */
/*   Updated: 2025/04/16 16:49:56 by nsaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

/*int	main(void)
{
	//t_list	*node1;
	//t_list	*node2;
	//char	*str1;
	//char	str2[] = "Cafe";

	//node1 = malloc(sizeof(t_list));
	//node2 = malloc(sizeof(t_list));
	//str1 = malloc(3);
	//str1[0] = 'o';
	//str1[1] = 'i';
	//str2[2] = '\0';
	//node1 -> content = str1;
	//node2 -> content = str2;
	//node1 -> next = node2;
	//node2 -> next = NULL;
	//ft_lstdelone(node1, &free);
	//free(node2);
	ft_lstdelone(NULL, NULL);
	return (0);
}*/
