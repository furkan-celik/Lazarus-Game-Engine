#pragma once

#include "../Utils/FileUtils.h"
#include "../Math/mat4.h"
#include <GL\glew.h>
#include <vector>
#include <iostream>

//Author: Furkan Celik Date: 22.12.2018

namespace Lazarus { namespace Graphics {

	class Shader //this class will take care of shader operations
	{
	public:
		Shader(const char *_vertPath, const char *_fragPath);
		~Shader();

		void enable() const; //enabling shader
		void disable() const; //disabling shader

		inline GLuint& getShaderID() { return shaderID; } //returning shaderID for keep older versions of functions running
		inline GLint getUniformLocation(const GLchar* name) { return glGetUniformLocation(shaderID, name); } //returns uniformLocation of shader in case of need. Recommended over getShaderID()

		inline void setUniform(const GLchar* name, float value) { glUniform1f(getUniformLocation(name), value); } //setUniform function is overloaded for variety of inputs and outputs. It simply uniforms shader and given vector
		inline void setUniform(const GLchar* name, int value) { glUniform1i(getUniformLocation(name), value); }
		inline void setUniform(const GLchar* name, const Math::Vec2d& vector) { glUniform2f(getUniformLocation(name), vector.x, vector.y); }
		inline void setUniform(const GLchar* name, const Math::Vec3d& vector) { glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z); }
		inline void setUniform(const GLchar* name, const Math::Vec4d& vector) { glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w); }
		inline void setUniform(const GLchar* name, const Math::Mat4& vector) { glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, vector.elements); }

	private:
		GLuint shaderID;
		const char *vertPath, *fragPath;

		GLuint load(); //will load shader and returns id for it
	};

} }