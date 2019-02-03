#include "BatchRenderer2D.h"

//Author: Furkan Celik Date: 12.01.2019

namespace Lazarus { namespace Graphics {


	BatchRenderer2D::BatchRenderer2D()
	{
		init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		delete ibo;
		glDeleteBuffers(1, &vbo);
	}

	void BatchRenderer2D::init()
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * sizeof(GLfloat)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLushort indices[RENDERER_INDICES_SIZE];

		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
			indices[i]		= offset + 0;
			indices[i + 1]	= offset + 1;
			indices[i + 2]	= offset + 2;

			indices[i + 3]	= offset + 2;
			indices[i + 4]	= offset + 3;
			indices[i + 5]	= offset + 0;

			offset += 4;
		}

		ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
		glBindVertexArray(0);
	}

	void BatchRenderer2D::Begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::Submit(const Renderable2D * renderable)
	{
		const Math::Vec2d& size = renderable->GetSize();
		const Math::Vec3d& position = renderable->GetPosition();
		const Math::Vec4d& color = renderable->GetColor();

		buffer->vertex = position;
		buffer->color = color;
		buffer++;

		buffer->vertex = Math::Vec3d(position.x, position.y + size.y, position.z);
		buffer->color = color;
		buffer++;

		buffer->vertex = Math::Vec3d(position.x + size.x, position.y + size.y, position.z);
		buffer->color = color;
		buffer++;

		buffer->vertex = Math::Vec3d(position.x + size.x, position.y, position.z);
		buffer->color = color;
		buffer++;

		indexCount += 6;
	}

	void BatchRenderer2D::End()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::Flush()
	{
		glBindVertexArray(vao);
		ibo->Bind();

		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_SHORT, NULL);

		ibo->Unbind();
		glBindVertexArray(0);

		indexCount = 0;
	}

}
}