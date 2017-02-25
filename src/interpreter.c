/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:09:35 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/25 16:32:40 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "interpreter.h"
#include "ft_printf.h"

t_ast	*expr(t_list **token);

void			error(size_t type)
{
	ft_printf("Parsing error at token type %zu", type);
	exit(1);
}

void	eat(size_t type, t_list **token)
{
	if ((*token)->content_size == type)
		*token = (*token)->next;
	else
		error((*token)->content_size);
}

t_ast	*factor(t_list **token)
{
	t_list	*node;
	t_ast	*ret;

	ret = NULL;
	if ((*token)->content_size == INTEGER)
	{
		node = *token;
		eat(INTEGER, token);
		return (ft_astnum(INTEGER, *(int *)node->content));
	}
	else
	{
		eat(LPAREN, token);
		ret = expr(token);
		eat(RPAREN, token);
	}
	return (ret);
}

t_ast	*term(t_list **token)
{
	size_t	op;
	t_ast	*ast;

	ast = factor(token);
	while ((*token)->content_size == TIMES || (*token)->content_size == DIVIDE)
	{
		op = (*token)->content_size;
		if (op == TIMES)
			eat(TIMES, token);
		else
			eat(DIVIDE, token);
		return (ft_astop(op, ast, factor(token)));
	}
	return (ast);
}

t_ast	*expr(t_list **token)
{
	size_t	op;
	t_ast	*ast;

	ast = term(token);
	while ((*token)->content_size == PLUS || (*token)->content_size == MINUS)
	{
		op = (*token)->content_size;
		if (op == PLUS)
			eat(PLUS, token);
		else
			eat(MINUS, token);
		return (ft_astop(op, ast, term(token)));
	}
	return (ast);
}

int		execution(t_ast *ast);

int		visit_op(t_ast *ast)
{
	if (ast->type == PLUS)
		return (execution(ast->left) + execution(ast->right));
	else if (ast->type == MINUS)
		return (execution(ast->left) - execution(ast->right));
	else if (ast->type == TIMES)
		return (execution(ast->left) * execution(ast->right));
	else
		return (execution(ast->left) / execution(ast->right));
}

int		visit_num(t_ast *ast)
{
	return (ast->value);
}

int		execution(t_ast *ast)
{
	if (!ast)
		return (0);
	if (ast->type == INTEGER)
		return (visit_num(ast));
	else
		return (visit_op(ast));
}

int				main(void)
{
	char	*str;
	t_list	*token;
	t_ast	*ast;

	get_next_line(0, &str);
	token = lexer(str);
	ast = expr(&token);
	ft_putnbr(execution(ast));
	free(str);
}
