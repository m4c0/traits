#pragma once
#include "ecow.hpp"

auto traits() {
  using namespace ecow;

  auto m = unit::create<mod>("traits");
  m->add_part("size_t");
  return m;
}
