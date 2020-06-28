#include "hello_window.h"

estatus hello_window() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(800, 600, "LearningOpenGL", NULL, NULL);

    if (window == NULL) {
        printf("Failed to create a GLFW window\n");
        glfwTerminate();
        return ERROR;
    }
    glfwMakeContextCurrent(window);

    // glad stuff
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return ERROR;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glClearColor(.4f, .2f, .6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);

    return SUCCESSFUL;
}