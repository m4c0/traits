export module traits:invoke;
import :concepts;

export namespace traits {
template <typename T> constexpr const auto always_false = false;
template <typename T> inline constexpr T &&declval() noexcept {
  static_assert(always_false<T>);
}

template <typename Fn, typename... Args> struct call_result {
  using type = decltype(declval<Fn>()(declval<Args>()...));
};

template <typename Fn, typename... Args>
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
static_assert(test([](int i) { return [i](long) -> int { return i; }; }(0)));
} // namespace
