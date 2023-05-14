#include "Model.h"


Model::Model(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices)
{
	m_vertices = vertices;
	m_indices = indices;

    SetBuffers();
    InitTransform();
}


void Model::SetBuffers()
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

    // vertex positions
    glEnableVertexAttribArray(0);
    //   - index: The index of the vertex attribute to set (in this case, position).
    //   - size: The number of components per vertex attribute (in this case, 3 for x, y, z coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE)
    //   - stride: size of a vertex in bytes (float x, y z, stride = 3*4).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (position is first that's why 0).
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

    // vertex colors
    glEnableVertexAttribArray(1);
    //   - index: The index of the vertex attribute to set (in this case, cp;pr).
    //   - size: The number of components per vertex attribute (in this case, 3 for r, g, b).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE).
    //   - stride: size of a vertex in bytes (float x, y z, r, g, b, t, s stride = 6*4).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (offset from start to normal element).
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));

    // vertex texture coords
    glEnableVertexAttribArray(2);
    //   - index: The index of the vertex attribute to set (in this case, texCoords).
    //   - size: The number of components per vertex attribute (in this case, 2 for u, v coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE).
    //   - stride: size of a vertex in bytes (float x, y z, r, g, b, t, s stride = 8*4).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (offset from start to texCoords element).
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, texCoords));

    // vertex normals
    glEnableVertexAttribArray(1);
    //   - index: The index of the vertex attribute to set (in this case, normal).
    //   - size: The number of components per vertex attribute (in this case, 3 for nx, ny, nz coordinates).
    //   - type: The data type of each component (in this case, GL_FLOAT).
    //   - normalized: Whether the data should be normalized before being stored in the buffer (in this case, GL_FALSE).
    //   - stride: size of a vertex in bytes (float x, y z, r, g, b, t, s, nx, ny, nz stride = 11*4).
    //   - pointer: the offset (in bytes) of the component from start of a buffer (offset from start to normal element).
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));


    if (!m_indices.empty())
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);
    }

    glBindVertexArray(0);
}

void Model::Draw(Engine::Shader *shader)
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
    glBindTexture(GL_TEXTURE0, 0);

}

void Model::SetTexture(Engine::Texture &texture)
{
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
}

void Model::Destroy()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Model::InitTransform()
{
    transform.position = glm::vec3(0.f);
    transform.rotation = glm::vec3(0.f);
    transform.localScale = glm::vec3(1.f);

    m_modelMat = glm::mat4(1.f);
    m_modelMat = glm::translate(m_modelMat, transform.position);
    m_modelMat = glm::rotate(m_modelMat, glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    m_modelMat = glm::rotate(m_modelMat, glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    m_modelMat = glm::rotate(m_modelMat, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    //m_modelMix = glm::translate(m_modelMatrix, m_transform.position - m_transform.origin);
    m_modelMat = glm::scale(m_modelMat, transform.localScale);
}

void Model::UpdateUniforms(Engine::Shader *shader)
{
    shader->setMat4("model", m_modelMat);
    //shader->setInt("grass_block", 0);
}