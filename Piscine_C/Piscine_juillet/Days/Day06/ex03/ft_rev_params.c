/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:00:45 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 09:00:46 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;

	while (--argc > 0)
	{
		i = 0;
		while (argv[argc][i])
		{
			ft_putchar(argv[argc][i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
