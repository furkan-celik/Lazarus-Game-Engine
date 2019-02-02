#pragma once

#include <GL\glew.h>
#include <vector>
#include "Buffer.h"

//Author: Furkan Celik Date: 23.12.2018

namespace Lazarus { namespace Graphics {

	class VertexArray //Vertex array will hold buffers, this will be handy when we are doing rendering. Vertex renderer will render objects in vertexArray.
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind()		const;
		void Unbind()	const;

		void addBuffer(Buffer* _buffer, GLuint _index); //adds new vector to vertexArray

	private:
		GLuint vertexArrayID;
		std::vector<Buffer*> buffers; //vector will hold Buffers by pointers, this will result in to a buffer can only be assigned and maintained by a single vertex array, if in constrast wanted to do, storing by cloning would be enough but will be higher memory consumption
	};

} }