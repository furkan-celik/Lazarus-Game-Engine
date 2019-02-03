#pragma once

#include "Renderable2D.h"

namespace Lazarus { namespace Graphics {

	class StaticSprite : public Renderable2D
	{
	public:
		StaticSprite(float _x, float _y, float _width, float _height, Math::Vec4d _color, Shader& _shader);
		~StaticSprite();

		inline const VertexArray* GetVAO()		const { return vertexArray; }	//returns VAO of sprite
		inline const IndexBuffer* GetIBO()		const { return indexBuffer; }	//returns IBO of sprite

		inline Shader& GetShader() const { return shader; } //returns shader of sprite

	private:
		VertexArray* vertexArray;
		IndexBuffer* indexBuffer;
		Shader& shader;

	};

} }