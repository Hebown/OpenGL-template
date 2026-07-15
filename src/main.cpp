#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

// 窗口大小变化回调
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // 1. 初始化 GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 配置 OpenGL 版本为 3.3 Core Profile (现代 OpenGL 的起点)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS 需要
#endif

    // 2. 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL modern Template", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 3. 初始化 GLAD (载入所有 OpenGL 函数指针)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 4. 打印当前 OpenGL 版本，验证是否是新版本
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // 测试 stb_image 是否能正常工作
    int width, height, nrChannels;
    // 只是测试编译，此处不需要真实图片，填空路径即可
    unsigned char *data = stbi_load("non_existent_image.png", &width, &height, &nrChannels, 0);
    if (data) {
        stbi_image_free(data);
    } else {
        std::cout << "stb_image loaded successfully (compiled ok, image file not found as expected)." << std::endl;
    }

    // 5. 渲染循环
    while (!glfwWindowShouldClose(window)) {
        // 输入
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // 渲染背景色（深蓝绿色）
        glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 交换缓冲和轮询事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 6. 释放资源
    glfwTerminate();
    return 0;
}