// compat.cc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: riley@google.com (Michael Riley)
//
// \file
// Google compatibility definitions.

#include <cstring>
#include <fst/compat.h>

using namespace std;

void FailedNewHandler() {
  cerr << "Memory allocation failed\n";
  exit(1);
}

unsigned long long __builtin_ctzll(unsigned long long v) {
  int c = 0;
  if (v) {
    v = (v ^ (v - 1)) >> 1;  // Set v's trailing 0s to 1s and zero rest
    for (c = 0; v; c++) {
      v >>= 1;
    }
  } else{
    c = CHAR_BIT * sizeof(v);
  }
  return c;
}

unsigned long long  __builtin_popcountll(unsigned long long  w) {
  std::bitset<64> bs = w;
  return bs.count();
}
