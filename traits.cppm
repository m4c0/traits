export module traits;
export import :concepts;
export import :decay;
export import :invoke;
export import :size_t;
export import :stdint;

export namespace traits {
template <class T> struct remove_ptr {
  typedef T type;
};
template <class T> struct remove_ptr<T *> {
  typedef T type;
};
template <class T> struct remove_ptr<T *const> {
  typedef T type;
};
template <class T> struct remove_ptr<T *volatile> {
  typedef T type;
};
template <class T> struct remove_ptr<T *const volatile> {
  typedef T type;
};
template <class T> using remove_ptr_t = typename remove_ptr<T>::type;

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

  template<typename T>
  unsigned offset_of(auto (T::*x)) {
    void * ptr = &(reinterpret_cast<T *>(0)->*x);
    return reinterpret_cast<traits::size_t>(ptr);
  }
} // namespace traits
