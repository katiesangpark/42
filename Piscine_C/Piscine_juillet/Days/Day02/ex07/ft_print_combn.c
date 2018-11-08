/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:45:18 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/05 17:45:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	get_max(int n, int *s, int *m)
{
	int min;
	int max;
	int n1;
	int reverse;

	n1 = n;
	reverse = 0;
	max = 9;
	while (n-- > 0)
		reverse = reverse * 10 + max--;
	max = 0;
	while (reverse != 0)
	{
		max = (max * 10) + (reverse % 10);
		reverse /= 10;
	}
	reverse = 0;
	min = 0;
	while (n1-- > 0)
		reverse = reverse * 10 + min++;
	*m = max;
	*s = reverse;
}

void	print_nbrs(int n, int *numbers, int last_number)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + numbers[i]);
		i++;
	}
	if (!last_number)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int i;
	int tmp;
	int n2;
	int max;
	int numbers[n];

	if (n <= 0 || n >= 10)
		return ;
	get_max(n, &i, &max);
	while (i <= max)
	{
		tmp = n - 1;
		n2 = i;
		while (tmp >= 0)
		{
			numbers[tmp] = n2 % 10;
			if (tmp + 1 < n && numbers[tmp] >= numbers[tmp + 1])
				tmp = -1;
			n2 /= 10;
			tmp--;
		}
		if (tmp == -1)
			print_nbrs(n, numbers, i == max);
		i++;
	}
}
