/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:07:20 by fgeruss           #+#    #+#             */
/*   Updated: 2019/08/22 16:20:52 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char				*ft_strnew_float(size_t size);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *destination, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(intmax_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);
long long int		ft_atoi_for_f(const char *str);
int					ft_atoi(const char *str);
int					ft_isdigit(int ch);
size_t				ft_strlen(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);

#endif
