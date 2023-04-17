#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



namespace Engine
{
	class Shader
	{
	private:
		void checkCompileErrors(unsigned int shader, std::string type);

	public:
		unsigned int ID;
		//const std::string vertexShaderSource =
		//	"#version 330 core\n"
		//	"layout (location = 0) in vec3 aPos;\n"
		//	"layout (location = 1) in vec3 aColor;\n"
		//	"out vec3 ourColor;\n"
		//	"void main()\n"
		//	"{\n"
		//	"   gl_Position = vec4(aPos, 1.0);\n"
		//	"   ourColor = aColor;\n"
		//	"}\0";

		//const std::string fragmentShaderSource =
		//	"#version 330 core\n"
		//	"out vec4 FragColor;\n"
		//	"in vec3 ourColor;\n"
		//	"void main()\n"
		//	"{\n"
		//	"   FragColor = vec4(ourColor, 1.0f);\n"
		//	"}\n\0";

		//unsigned int compile(unsigned int type, const std::string &src);
		//unsigned int create(const std::string &vertexShader, const std::string &fragmentShader);
		//void destroy();

		// constructor reads and builds the shader
		//Shader();
		Shader(const char *vertexPath, const char *fragmentPath);
		// use/activate the shader
		void use();
		// utility uniform functions
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setVec2(const std::string &name, const glm::vec2 &value) const;
		void setVec2(const std::string &name, float x, float y) const;
		void setVec3(const std::string &name, const glm::vec3 &value) const;
		void setVec3(const std::string &name, float x, float y, float z) const;
		void setVec4(const std::string &name, const glm::vec4 &value) const;
		void setVec4(const std::string &name, float x, float y, float z, float w) const;
		void setMat2(const std::string &name, const glm::mat2 &mat) const;
		void setMat3(const std::string &name, const glm::mat3 &mat) const;
		void setMat4(const std::string &name, const glm::mat4 &mat) const;
	
	};
}



#endif //SHADER_H

