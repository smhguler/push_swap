#include "../../include/push_swap.h"

int ft_putstr_fd(char *s, int fd)
{
    int len;

    if (!s)
        return (write(fd, "(null)", 6));
    len = (int)ft_strlen(s);
    write(fd, s, len);
    return (len);
}