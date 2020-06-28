#include "hello_triangle.h"


std::string get_vertex_shader();
std::string get_fragment_shader();
estatus sanity_check_shader_compilation(unsigned int id, std::string shader_type);
estatus sanity_check_program_compilation(unsigned int id);
void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


estatus hello_triangle_main() {
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

    // set up triangles and buffers
    float vertices[] = {
        -0.25f, -0.25f, 0.0f,
        -0.25f, 0.25f, 0.0f,
        0.5f, 0.5f, 0.5f
    };

    unsigned int vertex_buf_obj_id, vertex_arr_obj_id;
    int vertex_shader_id, frag_shader_id;
    unsigned int program_id;

    // set up shaders
    unsigned int program_id = create_shaders(get_vertex_shader(), get_fragment_shader());
    // const char* frag_src = get_fragment_shader();
    // const char* vertex_src = get_vertex_shader();
    const char *xvertex_src = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    const char *xfrag_src = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

    // -----------

    // @Edit: vertex array addition
    glGenVertexArrays(1, &vertex_arr_obj_id);
    // generate a vertex buffer object
    glGenBuffers(1, &vertex_buf_obj_id);
    // bind it to type GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buf_obj_id);
    // specify the vertex data and how to use it
    glBufferData(vertex_buf_obj_id, sizeof vertices, &vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    glDeleteShader(vertex_shader_id);
    glDeleteShader(frag_shader_id);


    while(!glfwWindowShouldClose(window)) {
        vertices[0] += 0.25f;

        if (vertices[0] > 1.0) {
            vertices[0] = -1.0f;
        }

        process_input(window);

        glClearColor(.4f, .2f, .6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program_id);
        glBindVertexArray(vertex_arr_obj_id); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);


        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    delete frag_src;
    delete vertex_src;

    return SUCCESSFUL;
}

std::string get_vertex_shader() {
    return R"glsl(
#version 330 core

layout(location = 0) in vec3 position;

void main() {
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
})glsl";
}

std::string get_fragment_shader() {
    return R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        } 
    )";
}

