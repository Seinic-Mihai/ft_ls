/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:53:15 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 14:24:50 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# define MODE(f, r) ((f & (r)) == (r))
# define ABS(x) (((x) < 0) ? (-x) : (x))

typedef struct		s_maxes
{
	int				max_size;
	int				max_nlink;
	int				max_blocks;
	int				max_gr;
	int				max_pw;
	int				max_maj;
	int				max_min;
	int				total;
	int				nbr;
}					t_maxes;

typedef struct		s_grpw
{
	char			gr[1024];
	char			pw[1024];
	int				status_pw;
	int				status_gr;
	int				grid;
	int				pwid;
}					t_grpw;

typedef	struct		s_args
{
	t_node			node;
	char			name[1024];
	struct stat		info;
	int				status;
	int				link_exist;
	char			link[1024];
	int				minor;
	int				major;
	t_grpw			grpw;
}					t_args;

typedef struct		s_env
{
	int				nbr_args;
	bool			flag[256];
	int				reg;
	int				dir;
	int				count_end;
	int				max_len;
}					t_env;

typedef struct		s_var
{
	DIR				*dirptr;
	struct dirent	*dp;
	t_args			tmp;
	t_tree			tree;
	t_maxes			max;
}					t_var;

void				print_blocks(t_args *av, t_maxes *max);
void				print_nlink(t_args *av, t_maxes *max);
void				print_size(t_args *av, t_maxes *max);
void				print_majmin(t_args *av, t_maxes *max);
void				print_pwgr(t_args *av, t_maxes *max);

int					time_cmp(t_args *n1, t_args *n2);
int					time_cmp2(t_args *n1, t_args *n2);
int					time_cmp3(t_args *n1, t_args *n2);
int					time_cmp4(t_args *n1, t_args *n2);
int					my_cmp2(t_args *n1, t_args *n2);
int					my_cmp3(t_args *n1, t_args *n2);

int					default_show(int ac, char *av);
void				ft_perror(char *str);
int					create_env(int ac, char **av, t_env *env);

int					show2(t_args *av, t_env *env, t_maxes *max);
int					show(t_args *av, t_env *env, t_maxes *max);
int					show_reg(t_args *av, t_env *env, t_maxes *max);
void				show_l(t_args *av, t_env *env, t_maxes *max);

void				open_dir(t_args *av, t_env *env);

void				get_flags_args(int ac, char **av, t_env *env);

void				print_rights(t_args *av);
int					get_lstat(t_args *ar);
void				get_tree(int index, int ac, char **av, t_env *env);

void				parc_in_order2(t_node *node, t_env *env, t_maxes *max);
void				parc_r(t_node *node, t_env *env);
void				parc_in_order(t_node *node, t_env *env, t_maxes *max);
int					ret_dir(t_args *tmp);

int					my_cmp(t_args *n1, t_args *n2);
int					my_cmp4(t_args *n1, t_args *n2);
void				max_len(t_maxes *max, t_args *av);
int					ret_len(int nbr);
void				append(char *src, char *append);
void				print_time(time_t file_time);
void				error_text(char *str);
void				print_total(t_env *env, t_maxes *max);
#endif
