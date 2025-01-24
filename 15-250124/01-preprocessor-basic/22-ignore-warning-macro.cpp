#ifdef __GNUC__
#define UNUSED_VARIABLE_PUSH \
    _Pragma("GCC diagnostic push") \
    _Pragma("GCC diagnostic ignored \"-Wunused-variable\"")
#define UNUSED_VARIABLE_POP \
    _Pragma("GCC diagnostic pop")
#elif _MSC_VER
// TODO
#else
#define UNUSED_VARIABLE_PUSH
#define UNUSED_VARIABLE_POP
#endif

int main() {
    UNUSED_VARIABLE_PUSH
    /* [[maybe_unused]] */ int x = 10;
    UNUSED_VARIABLE_POP
}
