/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcausse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:05:17 by kcausse           #+#    #+#             */
/*   Updated: 2018/02/17 12:05:17 by kcausse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 != '\0')
		return (nmatch(s1 + 1, s2 + 1));
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '*' && *s2 != '\0')
		return (match(s1 + 1, s2));
	return (0);
}
