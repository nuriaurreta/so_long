/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:24:46 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:19:20 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_integer(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		if (num == -2147483648)
			return (ft_print_str("-2147483648"));
		ft_printchar('-');
		num *= (-1);
		len++;
	}
	if (num <= 9)
	{
		ft_printchar(num + '0');
		len++;
	}
	else
	{
		len++;
		len += ft_print_integer(num / 10);
		ft_printchar (num % 10 + '0');
	}
	return (len);
}

/*int	main(void)
{
	int	num;
	int	print;

	num = -345678;
	print = ft_print_integer(num);
	printf("Total of characters printed: %d\n", print);
	return (0);
}*/
