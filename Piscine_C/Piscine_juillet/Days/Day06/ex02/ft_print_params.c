/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:56:57 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 08:56:58 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int x;

	x = 1;
	while (x < argc)
	{
		i = 0;
		while (argv[x][i])
		{
			ft_putchar(argv[x][i]);
			i++;
		}
		x++;
		ft_putchar('\n');
	}
	return (0);
}
