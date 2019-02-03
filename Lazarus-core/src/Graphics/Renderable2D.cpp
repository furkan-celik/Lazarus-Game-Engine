#include "Renderable2D.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	Renderable2D::~Renderable2D() //deletes vertexArray and indexBuffer since vertexArray will delete other member of this class automatically
	{
	}

	Renderable2D::Renderable2D(Math::Vec2d _size, Math::Vec3d _position, Math::Vec4d _color) : size(_size), position(_position), color(_color) { //constructor
	}

} }