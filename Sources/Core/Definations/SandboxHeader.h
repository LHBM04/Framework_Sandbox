#ifndef GUARD_SANDBOXHEADER_H
#define GUARD_SANDBOXHEADER_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// C++ 표준 라이브러리 (기본 유틸 용도)
#pragma region C++ Standards
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <exception>
#include <filesystem>
#include <functional>
#include <iostream>
#include <limits> 
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#pragma endregion
#pragma region Windows Platforms
#include <windows.h>

#pragma endregion

#include "SandboxTypes.h"

#endif // !GUARD_SANDBOXHEADER_H
