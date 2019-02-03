#pragma once

#include <GL\glew.h>

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {

	class IndexBuffer //index buffer will hold index of vertices instead of vertices itself. Elements in index buffer will be indexes of wanted vertices in buffer. This will reduce load of renderer by reducing elements in buffer
	{
	public:
		IndexBuffer(GLushort* _data, GLsizei _count); //range of unsigned short probably will be enough to store all data
		IndexBuffer(GLuint* _data, GLsizei _count); //range of unsigned short probably will be enough to store all data
		~IndexBuffer();

		void Bind()		const;
		void Unbind()	const;

		void BindTo(GLuint _index);

		inline GLuint getCount() const { return count; }
	private:
		GLuint bufferID; //to store actual id of buffer provided by openGL
		GLuint count; //count of components to determine Vec2d, Vec3d or Vec4d
	};

} }