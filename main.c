#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
int ft_ret;
int og_ret;
int n = 42;

/* %c */
ft_ret = ft_printf("ft: %c\n", 'A');
og_ret = printf("og: %c\n", 'A');
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* NUL as char */
ft_ret = ft_printf("ft: %c|\n", '\0');
og_ret = printf("og: %c|\n", '\0');
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* %s */
ft_ret = ft_printf("ft: %s\n", "Hello, 42!");
og_ret = printf("og: %s\n", "Hello, 42!");
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* empty and NULL strings */
ft_ret = ft_printf("ft: %s|\n", "");
og_ret = printf("og: %s|\n", "");
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %s\n", (char *)NULL);
og_ret = printf("og: %s\n", (char *)NULL);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* %d / %i */
ft_ret = ft_printf("ft: %d\n", 42);
og_ret = printf("og: %d\n", 42);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %d\n", -42);
og_ret = printf("og: %d\n", -42);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %d\n", (int)-2147483648);
og_ret = printf("og: %d\n", (int)-2147483648);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* %u */
ft_ret = ft_printf("ft: %u\n", 42u);
og_ret = printf("og: %u\n", 42u);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %u\n", 4294967295u);
og_ret = printf("og: %u\n", 4294967295u);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* negative passed to unsigned */
ft_ret = ft_printf("ft: %u\n", -1);
og_ret = printf("og: %u\n", -1);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* %x / %X */
ft_ret = ft_printf("ft: %x\n", 255);
og_ret = printf("og: %x\n", 255);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %X\n", 255);
og_ret = printf("og: %X\n", 255);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* zero and UINT_MAX cases */
ft_ret = ft_printf("ft: %x\n", 0);
og_ret = printf("og: %x\n", 0);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %x\n", 4294967295u);
og_ret = printf("og: %x\n", 4294967295u);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* %p */
ft_ret = ft_printf("ft: %p\n", &n);
og_ret = printf("og: %p\n", &n);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_ret = ft_printf("ft: %p\n", (void *)NULL);
og_ret = printf("og: %p\n", (void *)NULL);
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

/* literal percent */
ft_ret = ft_printf("ft: 100%%\n");
og_ret = printf("og: 100%%\n");
ft_printf("ft_ret: %d / og_ret: %d\n\n", ft_ret, og_ret);

ft_printf("name; %s, age; %d\n", "mtajima", 19);

return (0);
}