/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:12:05 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/25 15:46:26 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# define INTEGER	1
# define PLUS		2
# define MINUS		3
# define TIMES		4
# define DIVIDE		5
# define LPAREN		6
# define RPAREN		7
# define END		8

typedef struct	s_ast
{
	struct s_ast	*left;
	struct s_ast	*right;
	size_t			type;
	int				value;
}				t_ast;

t_list	*lexer(char *str);

t_ast	*ft_astnum(size_t type, int value);
t_ast	*ft_astop(size_t type, t_ast *left, t_ast *right);

#endif
