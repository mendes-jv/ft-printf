<div align = center>

# Ft_Printf: You will recode printf and learn how to use variadic arguments.

[![Norminette and Build](https://github.com/mendes-jv/ft-printf/actions/workflows/main.yml/badge.svg)](https://github.com/mendes-jv/ft-printf/actions/workflows/main.yml)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/mendes-jv/ft-printf?color=green)
![Code size in bytes](https://img.shields.io/github/languages/code-size/mendes-jv/ft-printf?color=dark-green)
![Top language](https://img.shields.io/github/languages/top/mendes-jv/ft-printf?color=dark-green)
![Last commit](https://img.shields.io/github/last-commit/mendes-jv/ft-printf?color=dark-green)

</div>

## Index:

* [Grade](#grade)
* [Description](#description)
* [How to execute](#how-to-execute)

## Grade:

<div align = center>

![Ft Printf](https://game.42sp.org.br/static/assets/achievements/ft_printfm.png)

[![jovicto2's 42 Ft_Printf Score](https://badge42.vercel.app/api/v2/clj244ax4006908l8zkjw830s/project/3119400)](https://github.com/JaeSeoKim/badge42)

</div>

## Description:

Ft_Printf is the third project at 42. In short, this project consists of coding a library that contains a simplified version of the printf function. It's an extremely useful function that can be used in the next school's projects.

## The project:

<table>
      <thead>
        <tr>
            <th colspan=3><h4>Specifiers</h4></th>
        </tr>
        <tr>
            <th >Format Specifier</th>
            <th >Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">%</td>
            <td>% followed by another % character writes % to the screen.</td>
        </tr>
        <tr>
            <td align="center">c</td>
            <td>writes a single character.</td>
        </tr>
        <tr>
            <td align="center">s</td>
            <td>writes a character string.</td>
        </tr>
        <tr>
            <td align="center">p</td>
            <td>writes an implementation-defined character sequence defining a pointer address.</td>
        </tr>
        <tr>
            <td align="center">d or i</td>
            <td>writes a signed integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">u</td>
            <td>writes an unsigned integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">x or X</td>
            <td>writes an unsigned integer to hexadecimal representation.</td>
        </tr>
        <tr>
            <td align="center">o</td>
            <td>writes an unsigned integer to octal representation.</td>
        </tr>
        <tr>
            <td align="center">b</td>
            <td>writes an unsigned integer to binary representation.</td>
        </tr>
        <tr>
            <td align="center">f (mandatory only)</td>
            <td>writes a float number.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Flags (bonus only)</h4></th>
        </tr>
        <tr>
            <th>Flag</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">-</td>
            <td>Left justify the result within the field. By default it is right justified.</td>
        </tr>
        <tr>
            <td align="center">+</td>
            <td>Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a sign.</td>
        </tr>
        <tr>
            <td align="center">(space)</td>
            <td>If there is no sign, a space is attached to the beginning of the result.</td>
        </tr>
        <tr>
            <td align="center">#</td>
            <td>Used with x or X specifiers the value is preceded with 0x or 0X respectively for values different than zero.</td>
        </tr>
        <tr>
            <td align="center">0</td>
            <td>Leading zeros are used to pad the numbers instead of space.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=3><h4>Width</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">(integer)</td>
            <td>Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.</td>
        </tr>
    </tbody>
	<thead>
        <tr>
            <th colspan=3><h4>Precision</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">.(integer)</td>
            <td>For integer specifiers (d, i, u, x, X, o, b, f) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.</td>
        </tr>
    </tbody>
</table>


## How to execute:

First, clone this repository and `cd` into it:

```zsh
git clone https://github.com/mendes-jv/ft-printf && cd ft-printf
```

To use the function in your code, simply include its header:

```zsh
#include "ft_printf.h"
```

Or, if you want to test the bonus version of the functions (it's the same functions but with flags implementation):

```sh
#include "ft_printf_bonus.h"
```

Compile the library with:

```zsh
make
```
Or, if you want to compile the bonus version(recommendation):
```zsh
make bonus
```

Now, when compiling your code, add the source files and the required flag:   

```sh
[gcc | cc | clang] [flags] your_main.c src/mandatory/ft_printf.c libftprintf.a && ./a.out
```
Or, if you want to compile the bonus files:

```sh
[gcc | cc | clang] [flags] your_main.c src/bonus/ft_printf_bonus.c libftprintf.a && ./a.out
```

You can test the functions with the files provided by me in this respository using:

```sh
gcc -Wall -Werror -Wextra  main.c src/mandatory/ft_printf.c libftprintf.a && ./a.out
```
Or

```sh
gcc -Wall -Werror -Wextra  main.c src/bonus/ft_printf_bonus.c libftprintf.a && ./a.out
```
This functions is also avaliable to use at my other 42 project called [Libft](https://github.com/mendes-jv/libft).
