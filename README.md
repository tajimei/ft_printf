*This project has been created as part of the 42 curriculum by mtajima.*

# ft_printf

## Description

`ft_printf` is a project that reimplements the `printf()` function from the C standard library.
The main goal is to learn how variadic functions work in C. The project produces a library `libftprintf.a` that parses a format string and performs the corresponding conversions.

Supported format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c`      | Prints a single character |
| `%s`      | Prints a string |
| `%p`      | Prints a pointer address in hexadecimal format |
| `%d`      | Prints a decimal (base 10) integer |
| `%i`      | Prints an integer in base 10 |
| `%u`      | Prints an unsigned decimal (base 10) integer |
| `%x`      | Prints a number in hexadecimal (base 16) lowercase format |
| `%X`      | Prints a number in hexadecimal (base 16) uppercase format |
| `%%`      | Prints a percent sign |

## Instructions

### Compilation

```bash
# Build the library
make

# Cleanup
make clean    # Remove object files
make fclean   # Remove object files and libftprintf.a
make re       # fclean + all
```

### Linking with your project

```bash
# Link the library at compile time
cc main.c -L. -lftprintf -o my_program
```

### Usage example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d, Hex: %x\n", 42, 255);
    ft_printf("Pointer: %p\n", (void *)0x1234);
    return (0);
}
```

## Algorithm and Data Structure

### Overall design

The implementation of `ft_printf` is based on **sequential parsing of the format string**. The string is scanned one character at a time using an integer index `i`. Regular characters are written out as-is via `write()`, and whenever a `%` is detected and a following character exists, the next character is examined to determine which conversion to apply.

```
ft_printf("Hello %s, you are %d years old.\n", name, age)
          ↓
[1] 'H','e','l','l','o',' ' → output directly via write()
[2] '%s' → retrieve next argument (name) via va_arg() → output as string
[3] ',',' ','y','o','u'... → output directly via write()
[4] '%d' → retrieve next argument (age) via va_arg() → output as integer
[5] '\n' → output via write()
```

The main loop calls `ft_process()` on each position. `ft_process()` handles two cases:

- If the current character is `%` and a next character exists: calls `ft_convert()` and advances `i` by 2.
- Otherwise: outputs the character as-is and advances `i` by 1.

This means a lone `%` at the very end of the format string is treated as a literal `%` character.

### Handling variadic arguments

The following macros from `<stdarg.h>` are used:

- `va_start(ap, last)` : Initialize the variadic argument list
- `va_arg(ap, type)` : Retrieve the next argument as the specified type
- `va_end(ap)` : Clean up the argument list

### Conversion dispatch

Depending on the character following `%`, `ft_convert` calls the corresponding sub-function. Each sub-function returns the number of characters it output (or `-1` on write error), which `ft_printf` accumulates to produce the final return value.

```
ft_convert()
  └─ '%' detected
       ├─ 'c' → ft_putchar()
       ├─ 's' → ft_putstr()
       ├─ 'p' → ft_putptr()
       ├─ 'd' / 'i' → ft_putnbr()
       ├─ 'u' → ft_putunsigned()
       ├─ 'x' / 'X' → ft_puthex()
       └─ '%' → ft_putchar('%')
```

### Number conversion

To convert a number to a string, **recursion** is used. The function divides the number by its base repeatedly, printing digits from most significant to least significant.

Example: `ft_putunsigned(1234)`:
```
putunsigned(1234) → putunsigned(123) → putunsigned(12) → putunsigned(1)
                                                           prints '1'
                                        prints '2'
                    prints '3'
prints '4'
→ output: "1234"
```

For negative numbers in `ft_putnbr`, a `-` is printed first and the absolute value is converted as `unsigned int`. `INT_MIN` (-2147483648) is handled as a special case by delegating directly to `ft_putstr("-2147483648")`, which correctly propagates any write error via its return value.

### `ft_strlen` return type

`ft_strlen` returns `int` (not `size_t`) so that its result can be used directly as the return value of `ft_putstr` and passed to `write()` without type mismatch warnings under `-Wall -Wextra -Werror`.

### Return value

`ft_printf` returns the **total number of characters** output. Each sub-function is also designed to return its own character count (or `-1` on error), which are summed up to produce the final return value. On write error, `-1` is propagated up through the entire call chain.

## Resources

### Official documentation & references

- [printf(3) - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) - Linux man page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [C Standard Library Reference - cppreference.com](https://en.cppreference.com/w/c/io/fprintf)
- [42 Norm](https://github.com/42School/norminette)

### Use of AI

In this project, AI was used strictly for the following purposes:

- **Translation**: translating the subject for comprehension, and translating the README into English
- **Concept clarification**: asking questions to verify understanding of `va_list` and variadic functions

AI was not used for code generation or completion. The entire implementation was written independently, and any uncertainties were resolved through the subject, man pages, and peer learning.

---
*以下日本語版*

# ft_printf

## Description

`ft_printf` は、C標準ライブラリの `printf()` 関数を再実装するプロジェクトです。
可変長引数（variadic functions）の仕組みを学ぶことを主な目的としており、フォーマット文字列を解析して対応する変換を行うライブラリ `libftprintf.a` を作成します。

対応するフォーマット指定子：

| 指定子 | 説明 |
|--------|------|
| `%c`   | 1文字を出力する |
| `%s`   | 文字列を出力する |
| `%p`   | ポインタアドレスを16進数で出力する |
| `%d`   | 10進数の整数を出力する |
| `%i`   | 10進数の整数を出力する |
| `%u`   | 符号なし10進数の整数を出力する |
| `%x`   | 16進数（小文字）で整数を出力する |
| `%X`   | 16進数（大文字）で整数を出力する |
| `%%`   | パーセント記号を出力する |

## Instructions

### コンパイル

```bash
# libftprintf.aのビルド
make

# クリーン
make clean    # オブジェクトファイルを削除
make fclean   # オブジェクトファイルと libftprintf.a を削除
make re       # fclean + all
```

### 自分のプロジェクトへの組み込み

```bash
# コンパイル時にライブラリをリンクする
cc main.c -L. -lftprintf -o my_program
```

### 使用例

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d, Hex: %x\n", 42, 255);
    ft_printf("Pointer: %p\n", (void *)0x1234);
    return (0);
}
```

## Algorithm and Data Structure

### 全体の設計方針

`ft_printf` の実装は、**フォーマット文字列の逐次解析**を基本とします。整数インデックス `i` を使って文字列を先頭から1文字ずつ走査します。通常の文字はそのまま `write()` で出力し、`%` を検出した時点で次の文字を見てどの変換を行うかを判定します。

```
ft_printf("Hello %s, you are %d years old.\n", name, age)
          ↓
[1] 'H','e','l','l','o',' ' → write() でそのまま出力
[2] '%s' → va_arg() で次の引数(name)を取得 → 文字列として出力
[3] ',',' ','y','o','u'... → write() でそのまま出力
[4] '%d' → va_arg() で次の引数(age)を取得 → 数値として出力
[5] '\n' → write() で出力
```

メインループは各位置で `ft_process()` を呼び出します。`ft_process()` は2つのケースを処理します：

- 現在の文字が `%` かつ次の文字が存在する場合：`ft_convert()` を呼び出し、`i` を2進める。
- それ以外：文字をそのまま出力し、`i` を1進める。

これにより、フォーマット文字列の末尾にある単独の `%` はリテラルの `%` として扱われます。

### 可変長引数の扱い

C言語の `<stdarg.h>` が提供するマクロを使用します：

- `va_start(ap, last)` : 可変引数リストの初期化
- `va_arg(ap, type)` : 次の引数を指定した型で取得
- `va_end(ap)` : 引数リストの終了処理

### 変換ディスパッチ

`%` の次の文字に応じて `ft_convert` が対応するサブ関数を呼び出します。各サブ関数は出力した文字数（writeエラー時は `-1`）を返し、`ft_printf` はそれを合算して最終的な文字数を戻り値として返します。

```
ft_convert()
  └─ '%' 検出
       ├─ 'c' → ft_putchar()
       ├─ 's' → ft_putstr()
       ├─ 'p' → ft_putptr()
       ├─ 'd' / 'i' → ft_putnbr()
       ├─ 'u' → ft_putunsigned()
       ├─ 'x' / 'X' → ft_puthex()
       └─ '%' → ft_putchar('%')
```

### 数値変換の考え方

数値を文字列に変換する際は**再帰**を用います。基数で割り続けることで、上位桁から順に出力します。

例：`ft_putunsigned(1234)`:
```
putunsigned(1234) → putunsigned(123) → putunsigned(12) → putunsigned(1)
                                                           '1' を出力
                                        '2' を出力
                    '3' を出力
'4' を出力
→ 出力: "1234"
```

負数の場合（`ft_putnbr`）は先頭に `-` を出力し、絶対値を `unsigned int` として変換します。`INT_MIN`（-2147483648）は絶対値が `int` の範囲を超えるため、`ft_putstr("-2147483648")` に直接委譲する特別処理を行います。これにより writeエラーの戻り値も正しく伝播されます。

### `ft_strlen` の戻り値型について

`ft_strlen` は `size_t` ではなく `int` を返すようにしています。これにより、`ft_putstr` の戻り値として直接使用でき、`write()` への引数渡しでも型不一致の警告が `-Wall -Wextra -Werror` 環境で発生しません。

### 戻り値

`ft_printf` は出力した**総文字数**を返します。各サブ関数も自身が出力した文字数（エラー時は `-1`）を返すよう設計し、エラーはコールチェーン全体で上位に伝播されます。

## Resources

### 公式ドキュメント・リファレンス

- [printf(3) - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) - Linux man page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [C Standard Library Reference - cppreference.com](https://en.cppreference.com/w/c/io/fprintf)
- [42 Norm](https://github.com/42School/norminette)

### AIの使用について

本プロジェクトにおいて、AIは以下の用途に限定して使用しました：

- **翻訳**：subject理解のための和訳、README作成のための英訳
- **概念の確認**：`va_list` や可変長引数の仕組みについて、理解を確かめるための質問

コードの生成・補完にはAIを使用していません。実装はすべて自分自身で行い、不明な点は仕様書・manページ・ピアラーニングを通じて解決しました。