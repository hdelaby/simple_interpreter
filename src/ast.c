/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:34:29 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/25 15:53:09 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "interpreter.h"

t_ast	*ft_astop(size_t type, t_ast *left, t_ast *right)
{
	t_ast *newnode;

	newnode = (t_ast *)malloc(sizeof(t_ast));
	if (!newnode)
		return (NULL);
	ft_bzero(newnode, sizeof(t_ast));
	newnode->type = type;
	newnode->left = left;
	newnode->right = right;
	return (newnode);
}

t_ast	*ft_astnum(size_t type, int value)
{
	t_ast *newnode;

	newnode = (t_ast *)malloc(sizeof(t_ast));
	if (!newnode)
		return (NULL);
	ft_bzero(newnode, sizeof(t_ast));
	newnode->type = type;
	newnode->value = value;
	return (newnode);
}
