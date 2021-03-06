#pragma once
#include "Renderer2D.h"
#include "Buffers/Indexbuffer.h"

//Author: Furkan Celik Date: 12.01.2019

namespace Lazarus { namespace Graphics {

#define RENDERER_MAX_SPRITES	60000
#define	RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX	1

	class BatchRenderer2D : public Renderer2D
	{
	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		
		void Begin();
		void Submit(const Renderable2D* renderable) override;
		void End();
		void Flush() override;

	private:
		GLuint vao;
		GLuint vbo;
		IndexBuffer* ibo;
		GLsizei indexCount;
		VertexData* buffer;

		void init();
	};

} }