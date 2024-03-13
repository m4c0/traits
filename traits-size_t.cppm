export module traits:size_t;

// This is silly, but it is a big multiplatform mess. `stdint.h` works in most
// platforms, but WASI. `cstdint` works in most, but Android. Also, we might
// face symbol duplication due in VCRT. Yay...
export namespace traits {
using size_t = decltype(sizeof(0));
}
