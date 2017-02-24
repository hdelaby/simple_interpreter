/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:45:16 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/26 14:27:26 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_tab(t_list *lst)
{
	size_t	siz;
	char	**tab;
	char	**ptr;

	if (!lst)
		return (NULL);
	siz = ft_lstsize(lst);
	tab = (char **)malloc(sizeof(char *) * siz + 2);
	if (!tab)
		return (NULL);
	ptr = tab;
	while (lst)
	{
		*(tab++) = ft_strdup((char *)lst->content);
		lst = lst->next;
	}
	*tab = NULL;
	return (ptr);
}
