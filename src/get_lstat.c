/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 19:32:32 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 18:17:29 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_grpw(t_args *av)
{
	struct passwd	*const	tmp_pw = getpwuid(av->info.st_uid);
	struct group	*const	tmp_gr = getgrgid(av->info.st_gid);
	int						len;

	len = 0;
	if (tmp_pw != NULL)
	{
		len = ft_strlen(tmp_pw->pw_name);
		if (len < 1024)
			ft_memcpy(av->grpw.pw, tmp_pw->pw_name, 1024);
	}
	else
		av->grpw.status_pw = 1;
	av->grpw.pwid = av->info.st_uid;
	if (tmp_gr != NULL)
	{
		len = ft_strlen(tmp_gr->gr_name);
		if (len < 1024)
			ft_memcpy(av->grpw.gr, tmp_gr->gr_name, 1024);
	}
	else
		av->grpw.status_gr = 1;
	av->grpw.grid = av->info.st_gid;
}

int				get_lstat(t_args *ar)
{
	struct stat		tmp1;
	int				status;

	status = lstat(ar->name, &tmp1);
	if (status == -1)
		ar->status = status;
	else
	{
		ft_memcpy(&ar->info, &tmp1, sizeof(struct stat));
		ar->minor = minor(ar->info.st_rdev);
		ar->major = major(ar->info.st_rdev);
		get_grpw(ar);
		if (S_ISLNK(ar->info.st_mode))
		{
			ar->link_exist = 1;
			readlink(ar->name, ar->link, sizeof(ar->link) - 1);
		}
	}
	return (status);
}
