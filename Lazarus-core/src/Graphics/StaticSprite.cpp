#include "StaticSprite.h"

namespace Lazarus { namespace Graphics {

	StaticSprite::StaticSprite(float _x, float _y, float _width, float _height, Math::Vec4d _color, Shader& _shader): Renderable2D(Math::Vec2d(_width, _height), Math::Vec3d(_x, _y, 0), _color), shader(_shader) {
		vertexArray = new VertexArray(); //creating new vertexArray
										 //by vertices we will be created proper matrix for size of sprite
		GLfloat vertices[] = {
			0,		0,		0,
			0,		_height, 0,
			_width,	_height, 0,
			_width,	0,		0
		};
													   //by this way, we can convert vec3d object of color to mat4 object
		GLfloat colors[] = {
			_color.x, _color.y, _color.z, _color.w,
			_color.x, _color.y, _color.z, _color.w,
			_color.x, _color.y, _color.z, _color.w,
			_color.x, _color.y, _color.z, _color.w
		};

		vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0); //adding buffers to vertexArray as sperate layers (0 and 1)
		vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

		GLushort indices[] = { 0, 1, 2, 2, 3, 0 }; //creating indexBuffer for performance gain
		indexBuffer = new IndexBuffer(indices, 6);
	}

	StaticSprite::~StaticSprite()
	{
		delete vertexArray;
		delete indexBuffer;
	}

} }