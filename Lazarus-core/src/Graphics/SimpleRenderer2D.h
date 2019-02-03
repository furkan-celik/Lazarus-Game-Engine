#pragma once

#include <deque>
#include "Renderer2D.h"
#include "StaticSprite.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	class SimpleRenderer2D : public Renderer2D
	{
	public:

		void Submit(const Renderable2D* renderable);
		void Flush();

	private:
		std::deque<const StaticSprite*> renderQueue; //queue for sprites will be rendered. deque implementation used for this purpose
	};

} }