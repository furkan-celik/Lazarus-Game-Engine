#include "IndexBuffer.h"

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {

	IndexBuffer::IndexBuffer(GLushort * _data, GLsizei _count) : count(_count) //this code almost same with buffer class'es code. The only difference is instead of GL_ARRAY_BUFFER I used GL_ELEMENT_ARRAY_BUFFER in order to telling opengl that I am keeping indexes of elements
	{
		glGenBuffers(1, &bufferID);
		Bind(); //GL_ARRAY_BUFFER means this buffer is a array of datas
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(GLushort), _data, GL_STATIC_DRAW); //size is in bytes. Since I won't change data I used GL_STATIC_DRAW
		Unbind(); //unbinding
	}

	IndexBuffer::IndexBuffer(GLuint * _data, GLsizei _count) : count(_count) //this code almost same with buffer class'es code. The only difference is instead of GL_ARRAY_BUFFER I used GL_ELEMENT_ARRAY_BUFFER in order to telling opengl that I am keeping indexes of elements
	{
		glGenBuffers(1, &bufferID);
		Bind(); //GL_ARRAY_BUFFER means this buffer is a array of datas
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(GLuint), _data, GL_STATIC_DRAW); //size is in bytes. Since I won't change data I used GL_STATIC_DRAW
		Unbind(); //unbinding
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::BindTo(GLuint _index)
	{
		glVertexAttribPointer(_index, count, GL_UNSIGNED_SHORT, GL_FALSE, 0, 0);
	}
} }