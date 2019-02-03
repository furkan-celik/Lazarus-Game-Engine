#include "Sprite.h"

namespace Lazarus { namespace Graphics {

	Sprite::Sprite(float _x, float _y, float _width, float _height, Math::Vec4d _color) : Renderable2D(Math::Vec2d(_width, _height), Math::Vec3d(_x, _y, 0), _color) {

	}

	Sprite::~Sprite()
	{
	}

} }