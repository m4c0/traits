export module traits:decay;
import :concepts;

namespace traits {
template <typename T> struct decay {
  using type = T;
};
template <typename T> struct decay<T *> : decay<T> {};
template <typename T> struct decay<T &> : decay<T> {};
template <typename T> struct decay<T &&> : decay<T> {};
template <typename T> struct decay<const T> : decay<T> {};
template <typename T> struct decay<volatile T> : decay<T> {};
template <typename T> struct decay<const volatile T> : decay<T> {};

template <typename T> using decay_t = decay<T>::type;

static_assert(is_same_v<decay_t<int>, int>);
static_assert(is_same_v<decay_t<const int>, int>);
static_assert(is_same_v<decay_t<volatile int>, int>);
static_assert(is_same_v<decay_t<const volatile int>, int>);
static_assert(is_same_v<decay_t<int *>, int>);
static_assert(is_same_v<decay_t<const int *>, int>);
static_assert(is_same_v<decay_t<volatile int &>, int>);
static_assert(is_same_v<decay_t<const volatile int &&>, int>);
} // namespace traits
