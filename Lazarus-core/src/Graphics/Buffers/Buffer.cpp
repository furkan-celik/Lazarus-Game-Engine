#include "Buffer.h"

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {

	Buffer::Buffer(GLfloat * _data, GLsizei _count, GLuint _componentCount) : componentCount(_componentCount)
	{
		glGenBuffers(1, &bufferID); //generates buffer for us and stores id of generated buffer in bufferID
		Bind();
		glBufferData(GL_ARRAY_BUFFER, _count * sizeof(GLfloat), _data, GL_STATIC_DRAW); //size is in bytes. Since I won't change data I used GL_STATIC_DRAW
		Unbind();
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &bufferID);
	}

	void Buffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID); //GL_ARRAY_BUFFER means this buffer is a array of datas
	}

	void Buffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0); //unbinding
	}

	void Buffer::BindTo(GLuint _index)
	{
		glVertexAttribPointer(_index, componentCount, GL_FLOAT, GL_FALSE, 0, 0); //binds to vertex pointer. GL_FLOAT is because of I used GLfloat as stored data, and I did not want transpose feature
	}

} }