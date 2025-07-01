#ifndef GUARD_SANDBOXHEADER_HPP
#define GUARD_SANDBOXHEADER_HPP

// C++ 표준 라이브러리 (기본 유틸 용도)
#pragma region C++ Standard Headers
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
#include <format>
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

// Windows 플랫폼 라이브러리
#pragma region Windows Headers
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#pragma endregion

// OpenGL 그래픽 라이브러리
#pragma region OpenGL Headers
// OpenGL Core & Extensions
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

// FreeGLUT
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

// GLFW
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

// GLM
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#pragma endregion

#endif // !GUARD_SANDBOXHEADER_HPP
