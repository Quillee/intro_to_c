#ifndef HEADERS_H
#define HEADERS_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "dbg.h"

enum estatus {
    QUIT,
    STARTING,
    SUCCESSFUL,
    RUNNING,
    ERROR    
};

#endif