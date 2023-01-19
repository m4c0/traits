export module traits;

export namespace traits {
template <class T> struct remove_ref {
  typedef T type;
};
template <class T> struct remove_ref<T &> {
  typedef T type;
};
template <class T> struct remove_ref<T &&> {
  typedef T type;
};
template <class T> using remove_ref_t = typename remove_ref<T>::type;

template <class T> constexpr T &&fwd(remove_ref_t<T> &t) noexcept {
  return static_cast<T &&>(t);
}
template <class T> constexpr T &&fwd(remove_ref_t<T> &&t) noexcept { return t; }

template <class T> constexpr remove_ref_t<T> &&move(T &&t) noexcept {
  return static_cast<remove_ref_t<T> &&>(t);
}
} // namespace traits
