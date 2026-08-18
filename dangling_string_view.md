# Dangling string_view via Reassignment

## The problem
string_view stores only an address, not a copy of the data. If the underlying
std::string is reassigned to a value that no longer fits in its current storage
(often due to Small String Optimization limits, ~15-22 characters), std::string
allocates NEW memory and moves the data there — leaving any existing string_view
still pointing at the OLD, now-invalid address.

## Example (proven experimentally)
​```
std::string name{"Alex\n"};
std::string_view sv(name);
std::cout << sv;                    // OK: Alex
name = "Something else\n";          // triggers reallocation
std::cout << sv;                    // BROKEN: prints garbled text (e.g. "Somet")
​```

## Why this happens
- Short strings may be stored inline inside std::string (SSO).
- Reassigning to a longer string can force a new heap allocation.
- The string_view never "knows" the data moved — it keeps pointing at the old address.

## However, there is on but
Even if your new reassigment can contain less letters, it is quite unrecommended because C++ does not guarantee that everything will work. The advice is this:
Do not use std::string_view with reassignment because it will mostly give a garbage.
