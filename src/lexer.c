/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 10:27:25 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/25 13:12:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "interpreter.h"

static void	lex_error(void)
{
	ft_putendl_fd("Lexical error", 2);
	exit(1);
}

t_list	*lexer(char *str)
{
	t_list	*lst;
	t_list	*node;
	int		nb;

	lst = NULL;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str))
		{
			nb = ft_atoi(str);
			node = ft_lstnew(&nb, sizeof(int));
			node->content_size = INTEGER;
			while (ft_isdigit(*str))
				str++;
			str--;
		}
		else
		{
			node = ft_lstnew("", 1);
			if (*str == '+')
				node->content_size = PLUS;
			else if (*str == '-')
				node->content_size = MINUS;
			else if (*str == '*')
				node->content_size = TIMES;
			else if (*str == '/')
				node->content_size = DIVIDE;
			else if (*str == '(')
				node->content_size = LPAREN;
			else if (*str == ')')
				node->content_size = RPAREN;
			else
				lex_error();
		}
		ft_lstaddback(&lst, node);
		str++;
	}
	node = ft_lstnew("", 1);
	node->content_size = END;
	ft_lstaddback(&lst, node);
	return (lst);
}
