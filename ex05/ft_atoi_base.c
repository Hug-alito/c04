/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:46:46 by hrischma          #+#    #+#             */
/*   Updated: 2024/02/13 14:46:49 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
#include <math.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	test[] = "--214748364bc";
	char	base1[] = "test1+";
	char	base2[] = "ts2poneyvif";
	char	base3[] = "01";
	char	base4[] = "0123456789ABCDEF";
	
	ft_atoi_base(test, base1);
	printf("\n");
	ft_atoi_base(test, base2);
	printf("\n");
	ft_atoi_base(test, base3);
	printf("\n");
	ft_atoi_base(test, base4);
	printf("\n");
	
}
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base_conv_wr(long int nbr, char *base, int size)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= size)
	{
		ft_base_conv_wr(nbr / size, base, size);
		ft_base_conv_wr(nbr % size, base, size);
	}
	else
		ft_putchar(*(base + nbr));
}

int	ft_base_verif(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
		{
			return (0);
		}
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}	

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

int	ft_atoi_base(char *str, char *base)
{	
	int	r;
	int	size;

	size = 0;
	while (base[size] != '\0')
	{
		size++;
	}
	r = ft_atoi(str);
	if (r == 0 || ft_base_verif(base) == 0)
	{
		return (0);
	}
	ft_base_conv_wr(r, base, size);
	return (r);
}
