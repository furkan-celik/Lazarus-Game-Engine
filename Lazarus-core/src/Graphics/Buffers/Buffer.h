#pragma once

#include <GL\glew.h>

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {

	class Buffer //Buffer class can be thinked like sprites. Buffer stores mostly vertext datas to draw them to screen instead of drawing each sprite separately
	{
	public:
		Buffer(GLfloat* _data, GLsizei _count, GLuint _componentCount);
		~Buffer();

		void Bind()		const;
		void Unbind()	const;
		
		void BindTo(GLuint _index);

		inline GLuint getComponentCount() const { return componentCount; }
	private:
		GLuint bufferID; //to store actual id of buffer provided by openGL
		GLuint componentCount; //count of components to determine Vec2d, Vec3d or Vec4d
	};

} }