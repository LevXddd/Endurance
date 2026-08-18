# How we can choose between const and constexpr in std::string and std::string_view?
Actually, it's quite simple. As we know, std::string is a fairly complex type that allocated memory not at compile time(unlike int, double, and other fundamental types), but at runtime. Because of this, you can only use const with it - which guarantees the data will not be changed after creation. Using constexpr with std::string would be a mistake, because compile-time computation is impossible when memory allocation is involved. 
However, with std::string_view, you can use either const or constexpr - because string_view does not allocate any memory at all. Think of it as more of an introduction or reference to existing text, rather than something that owns its own data(because actually, to be honest, we use std::string_view only in parameters, in parameters we can use only const and not constexpr). 
| | `int`, `double`, etc. | `std::string` | `std::string_view` |
|---|---|---|---|
| Size known in advance? | ✅ Yes — always fixed (4 bytes, 8 bytes, etc.) | ❌ No — depends on how many characters | ✅ Yes — always fixed (pointer + length, ~16 bytes) |
| Needs to ask OS for memory while running? | ❌ No — compiler just reserves fixed space | ✅ Yes — genuine runtime request | ❌ No — never allocates, just points to existing data |
| Type of memory | **Stack** (fast, automatic) | **Heap** (flexible, but requires runtime request) | **None owned** — just references memory that already exists elsewhere |
| Can be `constexpr`? | ✅ Yes | ❌ No | ✅ Yes |
