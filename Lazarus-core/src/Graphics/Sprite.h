#pragma once

#include "Renderable2D.h"

namespace Lazarus { namespace Graphics {

	class Sprite : public Renderable2D
	{
	public:
		Sprite(float _x, float _y, float _width, float _height, Math::Vec4d _color);
		~Sprite();

	private:

	};

} }