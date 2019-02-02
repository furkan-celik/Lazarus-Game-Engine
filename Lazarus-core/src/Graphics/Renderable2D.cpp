#include "Renderable2D.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	Renderable2D::~Renderable2D() //deletes vertexArray and indexBuffer since vertexArray will delete other member of this class automatically
	{
		delete vertexArray;
		delete indexBuffer;
	}

	Math::Mat4 Renderable2D::UpdateTranslationMatrix() //calls translation function of Mat4 class wth parameter position to create proper translation matrix
	{
		return trans = Math::Mat4::translation(position);
	}

	Renderable2D::Renderable2D(Math::Vec2d _size, Math::Vec3d _position, Math::Vec4d _color, Shader& _shader) : size(_size), position(_position), color(_color), shader(_shader) { //constructor
		vertexArray = new VertexArray(); //creating new vertexArray
		//by vertices we will be created proper matrix for size of sprite
		GLfloat vertices[] = {
			0,		0,		0,
			0,		size.y, 0,
			size.x,	size.y, 0,
			size.x,	0,		0
		};
		vertexBuffer = new Buffer(vertices, 4 * 3, 3); //creates vertexBuffer using vertices
		//by this way, we can convert vec3d object of color to mat4 object
		GLfloat colors[] = {
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w
		};
		colorBuffer = new Buffer(colors, 4 * 4, 4); //creating colorBuffer using colors

		vertexArray->addBuffer(vertexBuffer, 0); //adding buffers to vertexArray as sperate layers (0 and 1)
		vertexArray->addBuffer(colorBuffer, 1);

		GLushort indices[] = { 0, 1, 2, 2, 3, 0 }; //creating indexBuffer for performance gain
		indexBuffer = new IndexBuffer(indices, 6);

		UpdateTranslationMatrix(); //calls updateTranslationMatrix for initialization of translation matrix
	}

} }