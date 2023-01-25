export module traits:invoke;
import :concepts;

namespace traits {
template <typename T> constexpr const auto always_false = false;
template <typename T> static constexpr T &&declval() noexcept {
  static_assert(always_false<T>);
}

template <typename Fn, typename... Args> struct call_result {
  using type = decltype(declval<Fn>()(declval<Args>()...));
};

export template <typename Fn, typename... Args>
using call_result_t = typename call_result<Fn, Args...>::type;
} // namespace traits

namespace {
using namespace traits;

static_assert(is_same_v<int, call_result_t<int()>>);
static_assert(is_same_v<void, call_result_t<void(int), int>>);

template <typename Fn> static constexpr bool test(Fn &&fn) {
  return is_same_v<int, call_result_t<Fn, long>>;
}
static constexpr int fn(long) { return {}; }
static_assert(test(fn));
static_assert(test([](long) -> int { return {}; }));
} // namespace
