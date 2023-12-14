/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:49:51 by nuria             #+#    #+#             */
/*   Updated: 2023/11/23 16:18:57 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

/*int	main(void)
{
	char	c;
	int		i;

	c = 'a';
	i = ft_printchar(c);
	printf("the integer is: %d", i);
}*/
