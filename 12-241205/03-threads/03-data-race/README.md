std::cout is bytewise thread-safe: https://eel.is/c++draft/input.output#iostream.objects.overview-7

Data race is UB, even with `sleep`.
