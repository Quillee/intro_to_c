#include "common.h"

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

void framebuffer_size_callback(GLFWwindow* w, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* create_win() {
    return glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
}

static unsigned int compile_shader( unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    std::string shader_type = type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
    check(sanity_check_shader_compilation(id, shader_type) != ERROR, "%s shader type failed in compilation step. More info above.\n", shader_type);
    // int result;
    // glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    // if (result == GL_FALSE) {
    //     int len;
    //     glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
    //     // allocates on the stack
    //     char* message = (char*)_alloca(len * sizeof(char));
    //     glGetShaderInfoLog(id, len, &len, message);
    //     std::cout << "[ERROR]" << message << std::endl;
    //     glDeleteShader(id);
    //     return 0;
    // }

    return id;
error:
    return 0;
}

unsigned int create_shaders(const std::string& vertex_shader, const std::string& frag_shader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    unsigned int fs = compile_shader(GL_FRAGMENT_SHADER, frag_shader);

    if (fs == 0 || vs == 0) goto error;

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    check(sanity_check_program_compilation(program) != ERROR, "");
    glValidateProgram(program);

    glDetachShader(program, vs);
    glDetachShader(program, fs);
    // the shader has already been linked, so you can just delete the shader
	glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
error:
    return -1;
}

void enter_module(char* module_name) {
    printf("Entering module %s\n\n", module_name);
}


void fire_events(GLFWwindow* win) {
	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(win, true);
	}
}

estatus sanity_check_program_compilation(unsigned int id) {
    int success;
    char message[512];

    glGetProgramiv(id, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, message);
        log_err("ERROR::SHADER::PROGRAM::COMPILATION_FAILED \n%s\n", message);
        return ERROR;
    }
    return SUCCESSFUL;
}

estatus sanity_check_shader_compilation(unsigned int id, std::string shader_type) {
    int success;
    char message[512];

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(id, 512, NULL, message);
        log_err("ERROR::SHADER::%s::COMPILATION_FAILED \n%s\n", shader_type.c_str(), message);
        return ERROR;
    }
    return SUCCESSFUL;
}