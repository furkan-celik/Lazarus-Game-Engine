#include "VertexArray.h"

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {


	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &vertexArrayID); //will simply generate vertexArray and gets ID assigned to this creation
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < buffers.size(); i++)
			delete buffers[i];

		glDeleteVertexArrays(1, &vertexArrayID);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(vertexArrayID); //binds vertex array
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0); //unbinds vertex array
	}

	void VertexArray::addBuffer(Buffer * _buffer, GLuint _index) //add buffer binds vertex array and buffer and than enables vertex array to be processed and calls bindTo function of buffer which binds buffer to this vertexArray. After all, it unbinds buffer and vertex array
	{
		Bind();
		_buffer->Bind();
		glEnableVertexAttribArray(_index);
		glVertexAttribPointer(_index, _buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
		_buffer->Unbind();
		Unbind();
	}

} }