*This project has been created as part of the 42 curriculum by zabdulja.*

## Description

**ft_printf** is a custom implementation of the C standard library function `printf()`. The goal of this project is to recreate the behavior of `printf()` by handling variadic arguments and formatted output, producing a static library `libftprintf.a` that can be linked into any C project.

The implementation supports the following format conversions:
- `%c` — Prints a single character
- `%s` — Prints a string (prints `(null)` for NULL pointers)
- `%p` — Prints a `void *` pointer in hexadecimal with `0x` prefix (prints `(nil)` for NULL)
- `%d` — Prints a decimal (base 10) number
- `%i` — Prints an integer in base 10
- `%u` — Prints an unsigned decimal (base 10) number
- `%x` — Prints a number in hexadecimal (base 16) lowercase
- `%X` — Prints a number in hexadecimal (base 16) uppercase
- `%%` — Prints a literal percent sign

The function returns the total number of characters printed, matching the behavior of the original `printf()`.

## Instructions

### Compilation

```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild from scratch
```

### Usage

After compilation, link `libftprintf.a` with your project:

```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

Include the header in your source files:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! You are number %d.\n", "world", 1);
    return (0);
}
```

## Algorithm and Data Structure

### Architecture

The implementation uses a **dispatch-based design**:

1. **Format parser** (`ft_printf.c`): Iterates through the format string character by character. When a `%` is encountered, the next character is read and dispatched to the appropriate conversion handler.

2. **Conversion handlers** (one file per conversion type): Each handler is responsible for writing its output directly to `stdout` via `write()` and returning the count of characters written.

3. **Return value accumulation**: Each handler returns the number of bytes written. The main function accumulates these counts and returns the total.

### Key Design Decisions

- **Recursive printing for numbers**: Hexadecimal, decimal, and unsigned conversions use recursion to print digits from most-significant to least-significant without needing a buffer or string reversal.
- **No buffer management**: As specified by the subject, no internal buffering is implemented — all output goes directly through `write()`.
- **INT_MIN handling**: The edge case of `-2147483648` is handled explicitly since negating it would cause integer overflow.
- **Separate length calculation**: Length-counting functions are separate from printing functions to cleanly return the character count without mixing concerns.

### Data Structures

No complex data structures are used. The project relies on:
- `va_list` from `<stdarg.h>` for variadic argument handling
- Static character arrays for hex digit lookup tables

## Resources

- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C — cppreference](https://en.cppreference.com/w/c/variadic)
- [42 ft_printf subject](https://projects.intra.42.fr/)

### AI Usage

AI was not used for this project.
