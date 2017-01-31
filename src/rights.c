/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:07:28 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 13:58:13 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		check1(char *str, struct stat const st)
{
	if (S_ISREG(st.st_mode))
		str[0] = '-';
	else if (S_ISDIR(st.st_mode))
		str[0] = 'd';
	else if (S_ISBLK(st.st_mode))
		str[0] = 'b';
	else if (S_ISCHR(st.st_mode))
		str[0] = 'c';
	else if (S_ISFIFO(st.st_mode))
		str[0] = 'p';
	else if (S_ISLNK(st.st_mode))
		str[0] = 'l';
	else if (S_ISSOCK(st.st_mode))
		str[0] = 's';
}

static void		check2(char *str, struct stat const st)
{
	if (MODE(st.st_mode, S_IRUSR))
		str[1] = 'r';
	if (MODE(st.st_mode, S_IWUSR))
		str[2] = 'w';
	if (MODE(st.st_mode, S_IXUSR))
		str[3] = 'x';
	if (str[3] == 'x' && MODE(st.st_mode, S_ISUID))
		str[3] = 's';
	else if (MODE(st.st_mode, S_ISUID))
		str[3] = 'S';
}

static void		check3(char *str, struct stat const st)
{
	if (MODE(st.st_mode, S_IRGRP))
		str[4] = 'r';
	if (MODE(st.st_mode, S_IWGRP))
		str[5] = 'w';
	if (MODE(st.st_mode, S_IXGRP))
		str[6] = 'x';
	if (str[6] == 'x' && MODE(st.st_mode, S_ISGID))
		str[6] = 's';
	else if (MODE(st.st_mode, S_ISGID))
		str[6] = 'S';
}

static void		check4(char *str, struct stat const st)
{
	if (MODE(st.st_mode, S_IROTH))
		str[7] = 'r';
	if (MODE(st.st_mode, S_IWOTH))
		str[8] = 'w';
	if (MODE(st.st_mode, S_IXOTH))
		str[9] = 'x';
	if (str[9] == 'x' && MODE(st.st_mode, S_ISVTX))
		str[9] = 't';
	else if (MODE(st.st_mode, S_ISVTX))
		str[9] = 'T';
}

void			print_rights(t_args *av)
{
	char				str[13];
	int					i;
	struct stat const	st = av->info;
	acl_t				acl;

	acl = NULL;
	i = -1;
	while (++i < 12)
		str[i] = '-';
	str[i] = '\0';
	check1(str, st);
	check2(str, st);
	check3(str, st);
	check4(str, st);
	if (listxattr(av->name, NULL, 0, XATTR_NOFOLLOW) > 1)
		str[10] = '@';
	else if ((acl = acl_get_file(av->name, ACL_TYPE_EXTENDED)))
		str[10] = '+';
	else
		str[10] = ' ';
	str[11] = ' ';
	ft_putstr(str);
	acl_free((void *)acl);
}
