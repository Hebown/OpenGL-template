cmake_minimum_required(VERSION 3.25)
project(OpenGLTemplate LANGUAGES C CXX)

# 设置 C++ 标准为现代的 C++17 或 C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# 1. 寻找依赖（这些库会被 vcpkg 自动下载、编译并提供给 CMake）
# ---------------------------------------------------------------------------
# 寻找 GLFW3
find_package(glfw3 CONFIG REQUIRED)

# 寻找 GLAD (OpenGL 载入器)
find_package(glad CONFIG REQUIRED)

# 寻找 STB (图片解析库)
find_package(Stb REQUIRED)

# 寻找系统自带的 OpenGL 基础库（在 Windows 上是 opengl32.lib，Linux 上是 libGL.so 等）
find_package(OpenGL REQUIRED)

# ---------------------------------------------------------------------------
# 2. 创建可执行文件
# ---------------------------------------------------------------------------
# 假设你的源代码放在 src 目录下
add_executable(OpenGLApp 
    src/main.cpp
)

# ---------------------------------------------------------------------------
# 3. 链接库
# ---------------------------------------------------------------------------
# 现代 CMake 推荐 target_link_libraries，它会自动处理头文件搜索路径和库链接
target_link_libraries(OpenGLApp
    PRIVATE
        glfw                     # GLFW 窗口库
        glad::glad               # GLAD 载入库 (提供现代 OpenGL 函数)
        OpenGL::GL               # 系统 OpenGL 核心
)

# 因为 stb 是一个纯头文件库，vcpkg 导出的标准变量是 ${Stb_INCLUDE_DIR}
# 我们把它作为头文件目录加入到我们的 target 中
target_include_directories(OpenGLApp PRIVATE ${Stb_INCLUDE_DIR})