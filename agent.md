# agent.md

> **Agent Meta-Prompt**:
> This document is a project configuration guide for AI Assistants (Agents) and Developers. Follow the instructions below to configure, compile, and run this OpenGL Template project.

---

## 项目基本信息 (Project Info)

这是一个基于现代 C++ 的跨平台 **OpenGL 开发模板库**。项目已经集成了 C++ 主流的构建与包管理工具，实现了开箱即用。

### 技术栈与依赖 (Tech Stack & Dependencies)

* **C++ 标准**：C++17


* **构建系统**：CMake (最低要求 3.25) + Ninja


* **包管理器**：vcpkg (清单模式 / Manifest Mode)


* **核心依赖库**：


* **OpenGL**: 系统图形核心库。


* **GLFW3**: 跨平台窗口与输入管理器。


* **GLAD**: OpenGL 载入器 (Loader)，负责动态载入现代 OpenGL 函数指针。


* **STB**: 轻量级纯头文件图片解析库。





---

## 前置准备 (Prerequisites)

在开始配置项目前，请确保开发环境已就绪：

1. 安装 **CMake** (>= 3.25)。


2. 安装 **Ninja** 构建工具（或确保已安装对应的编译器如 MinGW / MSVC）。


3. 安装 **vcpkg**，并且**必须配置环境变量 `VCPKG_ROOT**` 指向你的 vcpkg 安装目录。


* 例如在 Windows 下，`VCPKG_ROOT` 应该指向类似 `D:/vcpkg` 的目录。





---

## 项目配置与构建 (Configuration & Build)

本项目全面采用 **CMake Presets** 进行统一管理，无需手动输入复杂的参数。

### 1. 配置项目 (Configure)

运行以下命令进行项目初始化和依赖解析。**首次运行会触发 vcpkg 自动下载、编译并本地安装所有第三方库，这会消耗一点时间。**

* **Debug 模式**：


```bash
cmake --preset debug

```


* **Release 模式**：


```bash
cmake --preset release

```



> **优化机制**：
> 
> 
> * 所有第三方库会被统一安全地安装在项目根目录下的 `./third_party/vcpkg` 目录。
> 
> 
> * 即使你完全删除了 `./build` 文件夹，重新配置时也**无需重新下载编译**第三方库。
> 
> 
> 
> 

### 2. 编译项目 (Build)

配置完成后，使用以下命令编译可执行文件：

* **Debug 编译**：
```bash
cmake --build build/debug

```


* **Release 编译**：
```bash
cmake --build build/release

```



---

## 代码阅读与补全 (Language Server Setup)

本项目针对 **`clangd`** 进行了深度适配，以提供极速且精准的代码跳转与补全支持。

* **多配置支持**：项目根目录已包含 `.clangd` 文件，它会自动在 `build/debug`、`build/release` 以及 `build` 目录下寻找导出的编译数据库 `compile_commands.json`。


* **使用建议**：
* 在你使用的编辑器中启用 `clangd` 插件。
* **切换 Preset 后**（如从 Debug 切到 Release），请确保运行一次对应的 `cmake --preset` 配置指令，使 `compile_commands.json` 同步更新。





---

## 项目结构概览 (Project Structure)

```text
.
├── .clangd                  # clangd 配置文件，提供代码补全路径引导[cite: 5]
├── agent.md                 # 本项目引导文件 (本文件)
├── CMakeLists.txt           # 主 CMake 构建脚本[cite: 2]
├── CMakePresets.json        # 预设的编译和环境配置 (定义了 base/debug/release)[cite: 1]
├── vcpkg.json               # 第三方依赖库清单管理[cite: 4]
├── src/
│   └── main.cpp             # 模板入口源文件，包含窗口初始化与 OpenGL 基础测试[cite: 2]
└── third_party/
    └── vcpkg/               # [自动生成] 存放 vcpkg 自动下载编译的二进制包[cite: 1]

