#ifndef CUBE_H
#define CUBE_H

#include "../Mesh.h"

class Cube
{
public:
    std::vector<unsigned int> indices;

    std::vector<Vertex> vertices = {
        // Position                         // Color                            // TexCoords                // Normals
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
    };

    Cube() {
        indices.push_back(1);
    }

private:

    //glm::vec3 pos;
    //glm::vec3 size;
};
#endif // !CUBE_H