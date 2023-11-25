/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:23:26 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:18:49 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printargs(va_list args, const char c)
{
	int	len_arg;

	len_arg = 0;
	if (c == 'c')
		len_arg += ft_printchar(va_arg(args, int));
	else if (c == 's')
		len_arg += ft_print_str(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		len_arg += ft_print_integer(va_arg(args, int));
	else if (c == 'u')
		len_arg += ft_print_integer_unsig(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len_arg += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len_arg += ft_print_pointer((unsigned long)va_arg(args, void *));
	else if (c == '%')
		len_arg += ft_printchar('%');
	return (len_arg);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	if ((ft_strlen(str) == 1) && str[i] == '%')
		return (len);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_printargs(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	unsigned long long	hex;
	int					p;
	char				*string;
	char				c;
	int					num2;
	unsigned int		num;

	hex = 255;
	p = 0x345;
	string = "totoro";
	c = 'x';
	num2 = -400;
	num = 4294967295;
	ft_printf("%X, %d, %u, %s, %p, %c\n", hex, num2, num, string, &p, c);
	printf("%llx, %d, %u, %s, %p, %c", hex, num2, num, string, &p, c);
}
