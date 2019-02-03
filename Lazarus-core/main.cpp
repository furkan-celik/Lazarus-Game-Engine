#include <iostream>
#include "src/Graphics/window.h"
#include "src/Math/Vectors.h"
#include "src/Math/mat4.h"
#include "src/Graphics/Shader.h"
#include "src/Graphics/Buffers/Buffer.h"
#include "src/Graphics/Buffers/IndexBuffer.h"
#include "src/Graphics/Buffers/VertexArray.h"
#include "src/Graphics/Renderable2D.h"
#include "src/Graphics/Renderer2D.h"
#include "src/Graphics/SimpleRenderer2D.h"
#include "src/Graphics/BatchRenderer2D.h"
#include "src/Graphics/StaticSprite.h"
#include "src/Graphics/Sprite.h"

int main() {
	
	using namespace Lazarus; using namespace Graphics; using namespace Math;

	Window window("Lazarus Test", 960, 540);
	glClearColor(0.2f, 0.23f, 0.46f, 1.0f);
	
	Shader shader("Components/Shaders/basic.vert", "Components/Shaders/basic.frag");
	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.enable();
	shader.setUniform("prMatrix", ortho);
	shader.setUniform("colour", Vec4d(0.2f, 1.0f, 0.8f, 1.0f));

	std::vector<Renderable2D*> sprites;
	for (float x = 0; x < 16.0f; x++) {
		for (float y = 0; y < 9.0f; y++) {
			sprites.push_back(new Sprite(x, y, 0.9f, 0.9f, Math::Vec4d(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	BatchRenderer2D renderer;

	while (!window.Closed()) {
		window.Clear();

		double x, y;
		window.GetMousePosVec(x, y);
		shader.setUniform("light_pos", Vec2d(x * 16.0f / window.GetWidth(), 9.0f - y * 9.0f / window.GetHeight()));

		renderer.Begin();
		for (int i = 0; i < sprites.size(); i++) {
			renderer.Submit(sprites[i]);
		}
		renderer.End();
		renderer.Flush(); 

		window.Update();
	}

	return 0;
}