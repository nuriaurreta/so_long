/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:22:49 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:19:46 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_hex(unsigned long long num, char c)
{
	unsigned int	i;

	i = 0;
	if (num < 16)
	{
		if (c == 'x')
			i += ft_printchar("0123456789abcdef"[num % 16]);
		else
			i += ft_printchar("0123456789ABCDEF"[num % 16]);
	}
	else
	{
		i += ft_print_hex(num / 16, c);
		if (c == 'x')
			i += ft_printchar("0123456789abcdef"[num % 16]);
		else
			i += ft_printchar("0123456789ABCDEF"[num % 16]);
	}
	return (i);
}

/*int	main(void)
{
	int		num;
	char	c;
	int		length_num;

	num = 255;
	c = 'x';
	length_num = ft_print_hex(num, c);
	return (0);
}*/
