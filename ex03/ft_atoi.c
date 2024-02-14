/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:52:04 by hrischma          #+#    #+#             */
/*   Updated: 2024/02/13 17:12:49 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
#include <math.h>

int	ft_atoi(char *str);

int	main(void)
{
	int a;
	char test1[] = "     +++---2147483648";
	char test2[] = "\n\t\r\f\v  --+100000abc";
	char test3[] = "\n\t\r\f\v---+--+ababc1515";
	a = ft_atoi(test1);
	printf("R : %d", a);
	a = ft_atoi(test2);
	printf("R : %d", a);
	a = ft_atoi(test3);
	printf("R : %d", a);
}
*/
int	ft_atoi(char *str)
{
	int	neg;
	int	res;
	int	i;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
	{
		i++;
	}
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
