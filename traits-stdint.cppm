export module traits:stdint;

export namespace traits::ints {
template <unsigned N> struct longint;

template <> struct longint<8> {
  using s = signed long;
  using u = unsigned long;
};
template <> struct longint<4> {
  using s = signed long long;
  using u = unsigned long long;
};

using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = typename longint<sizeof(long)>::u;
using int8_t = signed char;
using int16_t = signed short;
using int32_t = signed int;
using int64_t = longint<sizeof(long)>::s;
} // namespace traits::ints

namespace {
using namespace traits::ints;
static_assert(sizeof(uint8_t) == 1);
static_assert(sizeof(uint16_t) == 2);
static_assert(sizeof(uint32_t) == 4);
static_assert(sizeof(uint64_t) == 8);
static_assert(sizeof(int8_t) == 1);
static_assert(sizeof(int16_t) == 2);
static_assert(sizeof(int32_t) == 4);
static_assert(sizeof(int64_t) == 8);
} // namespace
