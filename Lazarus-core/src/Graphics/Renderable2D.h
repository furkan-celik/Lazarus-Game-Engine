#pragma once

#include <GL\glew.h>
#include "../Math/mat4.h"
#include "../Math/Vectors.h"
#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"
#include "Shader.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	struct VertexData //These datas are only for one vertex
	{
		Math::Vec3d vertex;
		Math::Vec4d color;
	};

	class Renderable2D //sprite 2D class
	{
	public:
		Renderable2D(Math::Vec2d _size, Math::Vec3d _position, Math::Vec4d _color, Shader& _shader); //basic constructor
		~Renderable2D(); //basic destructor

		inline const Math::Vec2d& GetSize()		const { return size; }			//returns size of sprite as type of vec2d 
		inline const Math::Vec3d& GetPosition() const { return position; }		//returns position of sprite as type of vec2d
		inline const Math::Vec4d& GetColor()	const { return color; }			//returns color of sprite as type of vec4d
		inline const Math::Mat4&  GetTrans()	const { return trans; }			//returns transformation matrix of sprite as type of mat4
		inline const VertexArray* GetVAO()		const { return vertexArray; }	//returns VAO of sprite
		inline const IndexBuffer* GetIBO()		const { return indexBuffer; }	//returns IBO of sprite
		
		inline Shader& GetShader() const { return shader; } //returns shader of sprite

		Math::Mat4 UpdateTranslationMatrix(); //updates translation matrix of object. TODO: make that function like whenever position of sprite changes, call this function automatically. Purpose of this preventing constructing a translation matrix for every frame
	protected:
		Math::Vec2d size; //size of sprite
		Math::Vec3d position; //z will be used for ordering in 2d view (front back ordering)
		Math::Vec4d color; //color of sprite
		Math::Mat4 trans; //translation matrix of sprite

		Buffer *colorBuffer, *vertexBuffer; //VAO and IBO of sprite
		VertexArray* vertexArray;
		IndexBuffer* indexBuffer;

		Shader& shader;

	};

} }