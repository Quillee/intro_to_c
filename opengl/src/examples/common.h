#ifndef COMMON_H
#define COMMON_H

#include "../head.h"

bool is_number(const std::string& s);
void framebuffer_size_callback(GLFWwindow* w, int width, int height);
unsigned int create_shaders(const std::string& vertex_shader, const std::string& frag_shader);
GLFWwindow* create_win();

#endif