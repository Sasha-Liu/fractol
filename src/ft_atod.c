#include "../include/fractol.h"

static double  ft_dec_part(char **str);
static double  ft_tenth_part(char **str);

//convert asci to double
double	ft_atod(char *str)
{
	double	sum;
	double	sign;

	sum = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
        str++;
	}
	sum += ft_dec_part(&str);
	if (*str == '.')
		str++;
	else
		return (sum * sign);
	sum += ft_tenth_part(&str);
	return (sum * sign);
}

//calculate until meet decimal point
static double  ft_dec_part(char **str)
{
    double  sum;

    sum = 0;
    while (**str >= '0' && **str <= '9')
	{
		sum = sum * 10 + (double)(**str - '0');
		(*str)++;
	}
    return (sum);
}

static double  ft_tenth_part(char **str)
{
    double  sum;
    double  power;

    sum = 0;
    power = 1;
    while (**str >= '0' && **str <= '9')
	{
		power = power / 10;
		sum += power * (double)(**str - '0');
		(*str)++;
	}
    return (sum);
}
