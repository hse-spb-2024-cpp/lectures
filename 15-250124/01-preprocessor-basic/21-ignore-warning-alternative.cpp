int main() {
#ifdef __GNUC__
    // `_Pramga` does not even look like preprocessor and can be embedded into a macro
    _Pragma("GCC diagnostic push")
    _Pragma("GCC diagnostic ignored \"-Wunused-variable\"")
#elif _MSC_VER
    // TODO
#endif
    /* [[maybe_unused]] */ int x = 10;
#ifdef __GNUC__
    _Pragma("GCC diagnostic pop")
#elif _MSC_VER
    // TODO
#endif
}
