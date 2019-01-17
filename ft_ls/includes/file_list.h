/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:27:58 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 23:27:59 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LIST_H
# define FILE_LIST_H

typedef struct	s_files
{
	char				*name;
	char				*prefix;
	char				*fullpath;
	int					exists;
	int					is_dir;
	int					is_exec;
	int					is_link;
	int					nlinks;
	unsigned long long	filesize;
	unsigned long long	access_time;
	char				*symlink_path;
	char				permission[13];
	char				*owner;
	char				*group;
	struct s_files		*next;
}				t_files;

typedef struct	s_folder
{
	char				*name;
	char				*prefix;
	char				*fullpath;
	int					exists;
	int					is_dir;
	int					is_exec;
	int					is_link;
	int					nlinks;
	unsigned long long	filesize;
	unsigned long long	access_time;
	char				*symlink_path;
	char				permission[13];
	char				*owner;
	char				*group;
	struct s_folder		*next;
	int					total;
	t_files				*files;
	struct s_folder		*subfolders;
}				t_folder;

t_files			*file_lst_new(char *name, char *prefix);
void			files_lst_push(t_files **begin, t_files *file);
int				folder_lst_size(t_folder *folder);

t_folder		*folder_lst_new(char *name, char *prefix);
void			folder_lst_push(t_folder **begin, t_folder *file);

#endif
