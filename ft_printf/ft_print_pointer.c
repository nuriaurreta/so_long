/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:05:46 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:19:12 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_print_pointer(unsigned long long num)
{
	int	printed;

	printed = ft_print_str("0x");
	printed += ft_print_hex(num, 'x');
	return (printed);
}

/*int	main(void)
{
	unsigned long long	ptr_value;

	ptr_value = 0x34567;
	ft_print_pointer(ptr_value);
	return (0);
}*/
