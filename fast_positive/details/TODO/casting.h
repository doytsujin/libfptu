﻿/*
 *  Fast Positive Tuples (libfptu), aka Позитивные Кортежи
 *  Copyright 2016-2019 Leonid Yuriev <leo@yuriev.ru>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "fast_positive/details/essentials.h"
#include "fast_positive/details/exceptions.h"
#include "fast_positive/details/meta.h"
#include "fast_positive/details/types.h"
#include "fast_positive/details/utils.h"

namespace fptu {
namespace details {
/* TODO */

template <genus FROM, genus TO> struct casting {
  using type_from = typename meta::genus_traits<FROM>::value_type;
  using type_to = typename meta::genus_traits<TO>::value_type;

  constexpr casting() {
    throw std::invalid_argument("fptu: field type mismatch");
  }
  constexpr const type_to &operator()(const type_from &value) {
    (void)value;
    return meta::genus_traits<TO>::denil;
  }
};

} // namespace details
} // namespace fptu
