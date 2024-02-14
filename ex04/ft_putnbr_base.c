/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:34:58 by hrischma          #+#    #+#             */
/*   Updated: 2024/02/13 11:35:51 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	char	base1[] = "0123456789";
	char	base2[] = "ts2po neyvif";
	char	base3[] = "01";
	char	base4[] = "0123456789ABCDEF";
	
	int	nbr = 2147483647;

	ft_putnbr_base(nbr, base1);
	printf("\n");

	ft_putnbr_base(nbr, base2);
	printf("\n");

	ft_putnbr_base(nbr, base3);
	printf("\n");

	ft_putnbr_base(nbr, base4);

}
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base_conv_wr(long int nbr, char *base, int size)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		nbr = 2147483648;
	}
	else if (nbr < 0)
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

char	ft_count_base_verif(char *base)
{
	int	size;

	size = 0;
	while (base[size])
	{
		size++;
	}
	if (size <= 1)
	{	
		return (0);
	}
	return (size);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	int	size;

	size = ft_count_base_verif(base);
	if (ft_base_verif(base) && size)
	{
		ft_base_conv_wr(nbr, base, size);
	}
}
