#pragma once
#include "ecow.hpp"

auto traits() {
  using namespace ecow;

  auto m = unit::create<mod>("traits");
  m->add_part("concepts");
  m->add_part("invoke");
  m->add_part("stdint");
  m->add_part("size_t");
  return m;
}
