#include "../../include/push_swap.h"

int ft_putnbr_fd(int n, int fd)
{
    long    nb;
    int     count;

    count = 0;
    nb = n;
    if (nb < 0)
    {
        write(fd, "-", 1);
        nb = -nb;
        count++;
    }
    if (nb >= 10)
        count += ft_putnbr_fd(nb / 10, fd);
    write(fd, &"0123456789"[nb % 10], 1);
    count++;
    return (count);
}