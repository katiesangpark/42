/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:41:48 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 22:41:48 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define ERR_NO_ERR			(0)
# define ERR_MALLOC_FAIL	(-1)
# define ERR_INVALID_ARG	(1)

void	list_files(t_args *args, t_folder *curr);

#endif
