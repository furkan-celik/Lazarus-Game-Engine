#pragma once

#include <GL\glew.h>
#include "../Math/mat4.h"
#include "../Math/Vectors.h"
#include "Renderable2D.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	class Renderer2D //this is like an interface
	{
	protected:
		virtual void Submit(const Renderable2D* renderable) = 0; //this will add a new sprite to renderer
		virtual void Flush() = 0; //this will make renderer empty
	};

} }