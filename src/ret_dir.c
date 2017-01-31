/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 20:08:33 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 20:09:38 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ret_dir(t_args *tmp)
{
	DIR		*dirptr;
	char	str[1024];
	int		status;

	status = 0;
	ft_bzero(&str, 1023);
	if ((dirptr = opendir(tmp->link)) != NULL)
	{
		closedir(dirptr);
		status = 1;
	}
	if (tmp->link_exist == 1 && status == 0)
	{
		str[0] = '/';
		append(str, tmp->link);
		ft_bzero(tmp->link, 1023);
		append(tmp->link, str);
		if ((dirptr = opendir(str)) != NULL)
		{
			closedir(dirptr);
			status = 1;
		}
	}
	return (status);
}
