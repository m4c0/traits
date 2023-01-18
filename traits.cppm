export module traits;

namespace traits {
template <class T> struct remove_ref {
  typedef T type;
};
template <class T> struct remove_ref<T &> {
  typedef T type;
};
template <class T> struct remove_ref<T &&> {
  typedef T type;
};

template <class T> constexpr T &&fwd(typename remove_ref<T>::type &t) noexcept {
  return static_cast<T &&>(t);
}
template <class T>
constexpr T &&fwd(typename remove_ref<T>::type &&t) noexcept {
  return t;
}
} // namespace traits
