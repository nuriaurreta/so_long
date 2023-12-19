/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:58:27 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:17:33 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_print_hex(unsigned long long num, char c);
int		ft_print_integer(int num);
int		ft_print_integer_unsig(unsigned int num);
int		ft_print_pointer(unsigned long long num);
int		ft_printchar(char c);
int		ft_print_str(char *str);
size_t	ft_strlen(const char *str);
int		ft_printf(char const *str, ...);

#endif
