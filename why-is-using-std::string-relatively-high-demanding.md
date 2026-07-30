Here is the first problem:
std::string s{ "Hello, world!" };
You might think, what the complex is about this? Actually, quite a lot happens behing this scenes. The program makes a copy of "Hello, world!" and stores it into s.
This compiler scans the literal and counts how many characters are present(13 characters + null terminator \0), and then requests an allocation of 14 bytes for it. 
The operating system finds available memory and hands back an address to the string object. After that, the CPU copies each character - H, then e, then l.. - one by one, physically writing them into s' memory.
So while working with int, double, and other fundamental types is quite simple(just storing a fixed-size number directly), working with std::string is considerably more involved - it requires counting characters, requesting memory allocation, and copying data byte by byte.
```
void printString(std::string str) // str makes a copy of its initializer
{...}
int main()
{
    std::string s{ "Hello, world!" }; // s makes a copy of its initializer
    printString(s);...}
```
For example, this example proves the problem. You are copying a value to s, after this you again copy from s to a function. It requires a lot of resources.
Because of this, we have two options:
use const + & - but it will work only when you have only std::string. and if not it will not work.
or using std::string_view which is universal and works for every type(like string and not string) which is commonly used for function parameters
Nowadays all prefer to use std::sting_view in big codes, because other programmers might write just like printString("..."); instead of printString(s);
