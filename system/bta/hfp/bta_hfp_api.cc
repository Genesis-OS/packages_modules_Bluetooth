/*
 * Copyright 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "bta_hfp_api.h"

#ifdef __ANDROID__
#include <hfp.sysprop.h>
#endif

#define DEFAULT_BTA_HFP_VERSION HFP_VERSION_1_7

int get_default_hfp_version() {
#ifdef __ANDROID__
  static const int version =
      android::sysprop::bluetooth::Hfp::version().value_or(
          DEFAULT_BTA_HFP_VERSION);
  return version;
#else
  return DEFAULT_BTA_HFP_VERSION;
#endif
}
