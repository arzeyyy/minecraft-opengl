#include "Mesh.h"


Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices)
{
	m_vertices = vertices;
	m_indices = indices;

    SetBuffers();
    InitTransform();
}



void Mesh::SetBuffers() 
{
    //VBO - Vertex Buffer Object is used to store vertex data such as position, color, texture coordinates, etc
    //VAO - Vertex Array Object is used to define the layout of the vertex data stored in VBO.
    //EBO - Element Buffer Object is used to store the indices that define how vertices are connected to form triangles or other shapes.

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

    if (!m_indices.empty())
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);
    }

    // vertex positions
    glEnableVertexAttribArray(0);
    //   - index: The index of the vertex attribute to set (in this case, position).
    //   - size: The number of components per vertex attribute (in this case, 3 for x, y, z coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE)
    //   - stride: size of a vertex in bytes (float x, y z, stride = 12).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (position is first that's why 0).
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

    // vertex normals
    glEnableVertexAttribArray(1);
    //   - index: The index of the vertex attribute to set (in this case, normal).
    //   - size: The number of components per vertex attribute (in this case, 3 for x, y, z coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE).
    //   - stride: size of a vertex in bytes (float x, y z, stride = 12).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (offset from start to normal element).
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));

    // vertex texture coords
    glEnableVertexAttribArray(2);
    //   - index: The index of the vertex attribute to set (in this case, texCoords).
    //   - size: The number of components per vertex attribute (in this case, 2 for u, v coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE).
    //   - stride: size of a vertex in bytes (float x, y z, stride = 12).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (offset from start to texCoords element).
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, texCoords));

    glBindVertexArray(0);
}

void Mesh::Draw(Engine::Shader *shader) 
{
    UpdateUniforms(shader);
    shader->use();
        
    // draw
    glBindVertexArray(VAO);
    if(m_indices.empty())
        glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    else
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_indices.size()), GL_UNSIGNED_INT, 0);


    // unbind
    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);

}

void Mesh::SetTexture(Engine::Texture &texture)
{
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
}

void Mesh::Destroy()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::InitTransform()
{
    m_transform.position = glm::vec3(0.f);
    m_transform.rotation = glm::vec3(0.f);
    m_transform.scale = glm::vec3(1.f);

    m_modelMatrix = glm::mat4(1.f);
    m_modelMatrix = glm::translate(m_modelMatrix, m_transform.position);
    m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(m_transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(m_transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(m_transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    //m_modelMatrix = glm::translate(m_modelMatrix, m_transform.position - m_transform.origin);
    m_modelMatrix = glm::scale(m_modelMatrix, m_transform.scale);
}

void Mesh::UpdateUniforms(Engine::Shader *shader)
{
    shader->setMat4("model", m_modelMatrix);
}




