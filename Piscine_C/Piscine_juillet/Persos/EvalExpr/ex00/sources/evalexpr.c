/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:44:19 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 15:44:21 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	do_operation(int *n1, int n2, char operator)
{
	if (operator == '+')
		*n1 += n2;
	else if (operator == '-')
		*n1 -= n2;
	else if (operator == '*')
		*n1 *= n2;
	else if (n2 != 0)
	{
		if (operator == '/')
			*n1 /= n2;
		else if (operator == '%')
			*n1 %= n2;
	}
}

int		get_nbr_value(char **str)
{
	int n;

	if (**str == '(')
	{
		*str += 1;
		n = basic_operations(str);
		if (**str == ')')
			*str += 1;
		return (n);
	}
	n = ft_atoi(str);
	return (n);
}

int		advanced_operations(char **str)
{
	int		n1;
	int		n2;
	char	operator;

	n1 = get_nbr_value(str);
	while (**str)
	{
		operator = **str;
		if (is_basic_operator(operator) || operator == ')')
			return (n1);
		*str += 1;
		n2 = get_nbr_value(str);
		do_operation(&n1, n2, operator);
	}
	return (n1);
}

int		basic_operations(char **str)
{
	int		n1;
	int		n2;
	char	operator;

	n1 = advanced_operations(str);
	while (**str)
	{
		operator = **str;
		if (!is_basic_operator(operator))
			return (n1);
		*str += 1;
		n2 = advanced_operations(str);
		do_operation(&n1, n2, operator);
	}
	return (n1);
}

int		eval_expr(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[n++] = str[i];
		i++;
	}
	str[n] = '\0';
	return (basic_operations(&str));
}
