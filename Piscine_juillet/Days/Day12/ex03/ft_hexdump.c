/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:35:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 08:35:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	read_file(char *file, int hex_display)
{
	if (file == NULL)
		return ;
	ft_print_memory(file, ft_strlen(file), hex_display);
	free(file);
}

void	read_input(int hex_display)
{
	int		read_amount;
	char	buffer[BUFSIZE];
	char	*output;

	output = malloc(1);
	output[0] = 0;
	while ((read_amount = read(0, buffer, BUFSIZE)) > 0)
		concat_strings(&output, buffer, read_amount);
	read_file(output, hex_display);
}

void	read_single_file(char **argv, int i, int hex_display)
{
	if (file_exists(argv[i]) < 0)
		print_error_message(file_exists(argv[i]), argv[i]);
	else
		read_file(get_file(argv[i]), hex_display);
}

void	read_argument_files(int argc, char **argv, int i, int hex_display)
{
	char	*file;
	char	*tmp;

	file = malloc(2);
	file[0] = 0;
	while (i < argc)
	{
		if (file_exists(argv[i]) < 0)
			print_error_message(file_exists(argv[i]), argv[i]);
		else
		{
			tmp = get_file(argv[i]);
			if (tmp == NULL)
				return ;
			concat_strings(&file, tmp, ft_strlen(tmp));
		}
		i++;
	}
	read_file(file, hex_display);
}

int		main(int argc, char **argv)
{
	int		i;
	int		hex_display;

	i = 1;
	hex_display = get_option(argc, argv, &i);
	if (argc == 1 || (argc == 2 && hex_display))
		read_input(hex_display);
	else if (i + 1 != argc)
		read_argument_files(argc, argv, i, hex_display);
	else
		read_single_file(argv, i, hex_display);
	return (0);
}
