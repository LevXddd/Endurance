# Why is using `std::string` relatively high-demanding?

Here is the first problem:

```cpp
std::string s{ "Hello, world!" };
```

You might think: what's complex about this? Actually, quite a lot happens behind the scenes. The program makes a **copy** of `"Hello, world!"` and stores it into `s`.

The compiler scans the literal and counts how many characters are present (13 characters + a null terminator `\0`), then requests an allocation of 14 bytes for it. The operating system finds available memory and hands back an address to the string object. After that, the CPU copies each character — `H`, then `e`, then `l`... — one by one, physically writing them into `s`'s memory.

So while working with `int`, `double`, and other fundamental types is quite simple (just storing a fixed-size number directly), working with `std::string` is considerably more involved — it requires counting characters, requesting memory allocation, and copying data byte by byte.

```cpp
void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer
    printString(s);

    return 0;
}
```

This example demonstrates the problem clearly: you first copy the value into `s`, and then copy it *again* from `s` into the function. This requires a significant amount of resources for something as simple as printing a string.

## Two options to avoid this

Because of this, we have two options:

1. **Use `const` + `&`** — but this only avoids the extra copy when you're passing an existing `std::string` variable. If you're not, it won't help.
2. **Use `std::string_view`** — a universal tool that works efficiently for both `std::string` objects and raw string literals, most commonly used for function parameters.

Nowadays, most programmers prefer `std::string_view` in large codebases, because other developers might accidentally call the function like `printString("...")` instead of `printString(s)`, unknowingly triggering an expensive hidden copy.

**For example:**

```cpp
void printString(const std::string& str) { /* ... */ }

int main()
{
    std::string s{"hello"};

    printString(s);       // OK — works with optimization (no copying)
    printString("hello"); // Works, but NOT as efficiently as we'd hoped —
                           // this is exactly where we need the universal
                           // tool called std::string_view (mostly used in parameters).
}
```
