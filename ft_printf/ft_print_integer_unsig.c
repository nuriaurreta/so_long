/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer_unsig.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:40:19 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:19:29 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_integer_unsig(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 9)
	{
		ft_printchar(num + '0');
		len++;
	}
	else
	{
		len++;
		len += ft_print_integer_unsig(num / 10);
		ft_printchar(num % 10 + '0');
	}
	return (len);
}

/*int	main(void)
{
	unsigned int	num;
	int				result;

	num = 123456;
	result = ft_print_integer_unsig(num);
	printf("Number of digits: %d\n", result);
	return (0);
}*/
