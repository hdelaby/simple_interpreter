/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:12:05 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/24 16:23:14 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# define INTEGER	1
# define PLUS		2
# define MINUS		3
# define END		4

struct	s_token
{
	char	type;
	int		value;
};

struct	s_input
{
	char	*str;
	size_t	pos;
};

#endif
