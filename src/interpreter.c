/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:09:35 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/24 16:26:32 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "interpreter.h"

void			error(void)
{
	ft_putendl_fd("Parsing error", 2);
	exit(1);
}

struct s_token	get_next_token(struct s_input *input)
{
	struct s_token	token;

	ft_bzero(&token, sizeof(token));
	while (input->str[input->pos] == ' ')
		input->pos++;
	if (input->pos == ft_strlen(input->str))
		token.type = END;
	else if (ft_isdigit(input->str[input->pos]))
	{
		token.type = INTEGER;
		token.value = ft_atoi(input->str + input->pos);
		while (ft_isdigit(input->str[input->pos]))
			input->pos++;
		return (token);
	}
	else if (input->str[input->pos] == '+')
		token.type = PLUS;
	else if (input->str[input->pos] == '-')
		token.type = MINUS;
	else
		error();
	input->pos++;
	return (token);
}

struct s_token	eat(char type, struct s_token token, struct s_input *input)
{
	if (token.type == type)
	{
		token = get_next_token(input);
		return (token);
	}
	else
		error();
	return (token);
}

int				interpreter(char *str)
{
	struct s_token	token;
	int				left;
	int				right;
	int				op;
	struct s_input	input;

	input.str = str;
	input.pos = 0;
	token = get_next_token(&input);
	left = token.value;
	token = eat(INTEGER, token, &input);
	op = token.type;
	if (op == PLUS)
		token = eat(PLUS, token, &input);
	else
		token = eat(MINUS, token, &input);
	right = token.value;
	token = eat(INTEGER, token, &input);
	if (op == PLUS)
		return (left + right);
	return (left - right);
}

int				main(void)
{
	char			*str;

	get_next_line(0, &str);
	ft_putnbr(interpreter(str));
	free(str);
}
