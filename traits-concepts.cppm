export module traits:concepts;

namespace traits {
export struct true_t {
  static constexpr const auto value = true;
};
export struct false_t {
  static constexpr const auto value = false;
};

template <typename A, typename B> struct is_same : false_t {};
template <typename A> struct is_same<A, A> : true_t {};
static_assert(is_same<void, void>::value);
static_assert(!is_same<int, void>::value);

export template <typename A, typename B>
concept same_as = is_same<A, B>::value;
export template <typename A, typename B>
concept not_same_as = (!is_same<A, B>::value);
} // namespace traits