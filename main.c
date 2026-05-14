#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define TEST(label, fmt, ...) do { \
    printf("\n[%s]\n", label); \
    printf("  printf   : "); \
    int r1 = printf(fmt, ##__VA_ARGS__); \
    printf("\n"); \
    printf("  ft_printf: "); \
    int r2 = ft_printf(fmt, ##__VA_ARGS__); \
    printf("\n"); \
    if (r1 == r2) printf("  ret: OK (%d == %d)\n", r1, r2); \
    else          printf("  ret: NG (printf=%d, ft_printf=%d)\n", r1, r2); \
} while(0)

int main(void)
{
    /* ── %c ── */
    printf("\n===== 1: %%c =====\n");
    TEST("c: normal",      "%c", 'A');
    TEST("c: space",       "%c", ' ');

    /* ── %s ── */
    printf("\n===== 2: %%s =====\n");
    TEST("s: normal",      "%s", "hello");
    TEST("s: empty",       "%s", "");
    /* NULL は printf() では UB のため ft_printf 単独でテスト */
    printf("\n[s: NULL (ft_printf only)]\n");
    printf("  ft_printf: ");
    int rn = ft_printf("%s", (char *)NULL);
    printf("\n  ret=%d (expect 6 '(null)')\n", rn);

    /* ──  %p ── */
    printf("\n=====  3: %%p =====\n");
    int x = 42;
    TEST("p: valid ptr",   "%p", (void *)&x);
    /* NULL ptr: glibc は "(nil)" を出力するが仕様外のため ft_printf 単独 */
    printf("\n[p: NULL ptr (ft_printf only)]\n");
    printf("  ft_printf: ");
    int rp = ft_printf("%p", (void *)NULL);
    printf("\n  ret=%d (expect 5 '(nil)')\n", rp);
    TEST("p: fixed addr",  "%p", (void *)0x1234abcdUL);

    /* ── %d ── */
    printf("\n=====  4: %%d =====\n");
    TEST("d: zero",        "%d", 0);
    TEST("d: positive",    "%d", 42);
    TEST("d: negative",    "%d", -42);
    TEST("d: INT_MAX",     "%d", INT_MAX);
    TEST("d: INT_MIN",     "%d", INT_MIN);

    /* ── %i ── */
    printf("\n=====  5: %%i =====\n");
    TEST("i: zero",        "%i", 0);
    TEST("i: positive",    "%i", 123);
    TEST("i: negative",    "%i", -123);
    TEST("i: INT_MIN",     "%i", INT_MIN);

    /* ── %u ── */
    printf("\n=====  6: %%u =====\n");
    TEST("u: zero",        "%u", 0u);
    TEST("u: small",       "%u", 42u);
    TEST("u: UINT_MAX",    "%u", UINT_MAX);

    /* ── %x ── */
    printf("\n=====  7: %%x =====\n");
    TEST("x: zero",        "%x", 0);
    TEST("x: small",       "%x", 255);
    TEST("x: UINT_MAX",    "%x", UINT_MAX);

    /* ── %X ── */
    printf("\n=====  8: %%X =====\n");
    TEST("X: zero",        "%X", 0);
    TEST("X: small",       "%X", 255);
    TEST("X: UINT_MAX",    "%X", UINT_MAX);

    /* ── %% ── */
    printf("\n=====  9: %%%% =====\n");
    TEST("%%: single",     "100%%");
    TEST("%%: surrounded", "a%%b");

    /* ──  複合・エッジケース ── */
    printf("\n=====  10: 複合・エッジケース =====\n");
    TEST("mix: multiple",  "%s=%d hex=%x", "val", -1, 255u);
    printf("\n[edge: no specifier]\n");
    int r = ft_printf("hello\n");
    printf("  ft_printf ret=%d (expect 6)\n", r);
    printf("\n[edge: NULL format]\n");
    int rnull = ft_printf(NULL);
    printf("  ft_printf(NULL) ret=%d (expect -1)\n", rnull);

    return (0);
}
