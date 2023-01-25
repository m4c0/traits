export module traits:concepts;

namespace traits {
template <typename A, typename B> struct is_same {
  static constexpr const auto value = false;
};
template <typename A> struct is_same<A, A> {
  static constexpr const auto value = true;
};
static_assert(is_same<void, void>::value);
static_assert(!is_same<int, void>::value);

export template <typename A, typename B>
concept same_as = is_same<A, B>::value;
export template <typename A, typename B>
concept not_same_as = (!is_same<A, B>::value);
} // namespace traits
