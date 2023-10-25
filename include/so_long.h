/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:33 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/10/25 17:35:30 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

/*
=====================================
			STRUCTURE
=====================================
*/

typedef struct s_game
{
	int	i;
	int cpt;
	int upper;
	int lower;
	int left;
	int right;
	int end;
}		t_game;

int		ft_strlen(char *s);
int		main(int argc, char *argv[], char *env[]);
int		pr_error(char *error);

/*
=====================================
			PARSING
=====================================
*/

bool	parsing(char *argv[]);
bool	verif_map_outline(char *argv[]);
int		verif_map(char **argv);
char	**map_manager(char *argv[], char *evp[]);
char	*ft_get_path(char **env);
int		get_lenght(char *tmp, char *argv[]);
char	*get_final_path_map(char *argv[], char *env[]);

/*
=====================================
			GET_NEXT_LINE
=====================================
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_first_backup(char *backup, int fd);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_cpy(char *s1, char *s2, char *str);
char		*ft_str(char *backup);
char		*ft_clean(char *backup, int i);
char		*free_join(char *backup, char *buffer);
char		*ft_substr(char *s, int start, int len);
int			ft_find_newline(char *str);

/*
=====================================
			PRINTF et LIBFT
=====================================
*/

int					ft_putchar(char c);
void				ft_putnbr_base(unsigned int nbr, const char format);
int					ft_putstr(char *s);
int					ft_putnbr(int nbr);
int					ft_printf(const char *str, ...);
int					ft_count_base(unsigned int nbr);
int					ft_count(int nbr);
int					ft_putnbr_unsigned(unsigned int nbr);
int					ft_unsigned_count(unsigned int nbr);
int					ft_count_help(unsigned long long nbr, int cpt);
int					ft_ptr_len(uintptr_t num);
void				ft_put_ptr(uintptr_t num);
int					ft_print_ptr(unsigned long long ptr);
char				*ft_itoa(int n);
int					ft_print_hex(unsigned int nbr, const char format);
int					ft_strlen(char *str);
int					ft_letter(char const *s, char c, int i);
char				**ft_free(char **split, int index_word);
int					ft_word(char const *s, char c);
char				**ft_copy(char const *s, char c, char **split, int i);
char				**ft_split(char const *s, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*str_join_free(char *path, char *cmd);
char				*ft_cpyjoin(char const *s1, char const *s2, char *str);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

#endif