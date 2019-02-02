#include "Shader.h"

//Author: Furkan Celik Date: 22.12.2018

namespace Lazarus { namespace Graphics {

		Shader::Shader(const char * _vertPath, const char * _fragPath) : vertPath(_vertPath), fragPath(_fragPath) //assigns inputs to member variables and set shaderID to return of load
		{
			shaderID = load();
		}

		Shader::~Shader() //deletes both path variables and shader program
		{
			delete vertPath;
			delete fragPath;
			glDeleteProgram(shaderID); //undoes createProgram command and frees memory allocated for shader
		}

		void Shader::enable() const //enables shader by calling glUseProgram with shaderID
		{
			glUseProgram(shaderID); //installs shader to current rendering program
		}

		void Shader::disable() const //disables shader by calling glUseProgram with 0, this may cause disabling all shaders but engine will use one shader at the same time
		{
			glUseProgram(0);
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram(), vertex  = glCreateShader(GL_VERTEX_SHADER), fragment = glCreateShader(GL_FRAGMENT_SHADER); //creates program, vertex and fragment shaders
			std::string vertString = FileUtils::readFile(vertPath), fragString = FileUtils::readFile(fragPath); //calls readFile to read fragment and vertex shaders
			const char *vertSource = vertString.c_str(), *fragSource = fragString.c_str(); //converts strings to const char*. Doing conversion inline caused problems

			glShaderSource(vertex, 1, &vertSource, nullptr); //sets vertexSourve to created vertex shader. Length given nullptr since it is not a concern to use
			glCompileShader(vertex); //compiles given vertex shader source code

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result); //saves compile status of vertex shader to result variable
			if (result == GL_FALSE) { //if shader did not complied than logs error
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length); //returns number of characters in opengl info log
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]); //collects info log from opengl logs for that particular shader
				std::cout << "#Lazarus.Graphics.Shader Failed to compile vertex shader: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, nullptr); //same thing happens for fragment shader
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "#Lazarus.Graphics.Shader Failed to compile fragment shader: " << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex); //attaches vertex and fragment shaders to shader program. Attaching will put shader to linking process
			glAttachShader(program, fragment);

			glLinkProgram(program); //links and validates program. Linking will link shaders and program together so correct shader will run on correct processor (vertex shader to vertex processor etc.)
			glValidateProgram(program); //checkes final executable version of program and attached executables are correct in terms of opengl state. Information generated by function will be stored in opengl logs

			glDeleteShader(vertex); //deleting both vertex and fragment shaders since they will not be usefull for us and there is no need to keep them in memory
			glDeleteShader(fragment);

			return program;
		}

} }