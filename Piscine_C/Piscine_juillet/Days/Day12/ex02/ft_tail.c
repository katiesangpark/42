/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:35:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 08:35:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	read_file(char *file, int offset)
{
	int	startpos;

	if (offset < 0)
	{
		if (-offset > ft_strlen(file))
			startpos = 0;
		else
			startpos = ft_strlen(file) + offset;
	}
	else
		startpos = (offset == 0) ? (0) : (offset - 1);
	print(file + startpos);
	free(file);
}

void	print_filename(char *filename, int leading_newline)
{
	if (leading_newline)
		print("\n");
	print("==> ");
	print(filename);
	print(" <==\n");
}

void	read_input(int offset)
{
	int		read_amount;
	char	buffer[BUFSIZE];
	char	*output;

	output = malloc(1);
	output[0] = 0;
	while ((read_amount = read(0, buffer, BUFSIZE)) > 0)
		concat_strings(&output, buffer, read_amount);
	read_file(output, offset);
}

void	read_argument_files(char **argv, int i, int argc, int offset)
{
	int		show_filename;
	int		last_file_missing;
	char	*file;

	show_filename = argc - i > 1;
	last_file_missing = 0;
	while (i < argc)
	{
		if (!file_exists(argv[i]) && (last_file_missing = 1))
			print_error_message(-1, argv[i]);
		else
		{
			file = get_file(argv[i]);
			if (file == NULL)
				return ;
			if (show_filename)
				print_filename(argv[i], !last_file_missing && i != 3);
			read_file(file, offset);
			last_file_missing = 0;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		offset;
	int		error;

	error = 0;
	i = 2;
	offset = get_offset(argv, argc, &i, &error);
	if (error != 0)
	{
		print_error_message(error, argv[1]);
		return (0);
	}
	if (argc <= 2 || i == -2)
		read_input(offset);
	else
		read_argument_files(argv, i, argc, offset);
	return (0);
}
