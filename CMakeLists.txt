cmake_minimum_required(VERSION 3.25)
project(OpenGLTemplate LANGUAGES C CXX)

# 设置 C++ 标准为现代的 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------------------------
# 1. 寻找依赖
# ---------------------------------------------------------------------------
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)

# macOS 使用系统自带的 OpenGL Framework，不需要 find_package(OpenGL)
if(NOT APPLE)
    find_package(OpenGL REQUIRED)
endif()

# ---------------------------------------------------------------------------
# 2. 创建可执行文件
# ---------------------------------------------------------------------------
add_executable(OpenGLApp 
    src/main.cpp
    src/shader.cpp
)

# ---------------------------------------------------------------------------
# 3. 链接库
# ---------------------------------------------------------------------------
target_link_libraries(OpenGLApp
    PRIVATE
        glfw
        glad::glad
        glm::glm
)

if(APPLE)
    target_link_libraries(OpenGLApp PRIVATE "-framework OpenGL")
else()
    target_link_libraries(OpenGLApp PRIVATE OpenGL::GL)
endif()

# stb 是纯头文件库，vcpkg 提供的是 ${Stb_INCLUDE_DIR} 变量
target_include_directories(OpenGLApp PRIVATE ${Stb_INCLUDE_DIR})