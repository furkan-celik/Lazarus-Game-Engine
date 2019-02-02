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

int main() {
	
	using namespace Lazarus; using namespace Graphics; using namespace Math;

	Window window("Lazarus Test", 960, 540);
	glClearColor(0.2f, 0.23f, 0.46f, 1.0f);
	
	Shader shader("Components/Shaders/basic.vert", "Components/Shaders/basic.frag");
	Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.enable();
	shader.setUniform("prMatrix", ortho);
	shader.setUniform("colour", Vec4d(0.2f, 1.0f, 0.8f, 1.0f));

	Renderable2D sprite1(Vec2d(4.0f, 4.0f), Vec3d(5.0f, 5.0f, 0.0f), Vec4d(0.4f, 0.3f, 0.9f, 1), shader);
	Renderable2D sprite2(Vec2d(2.0f, 4.0f), Vec3d(7.0f, 1.0f, 0.0f), Vec4d(0.8f, 0.0f, 0.5f, 1), shader);
	Renderable2D sprite3(Vec2d(2.0f, 4.0f), Vec3d(5.0f, 1.0f, 0.0f), Vec4d(0.0f, 0.8f, 0.5f, 1), shader);
	SimpleRenderer2D renderer;

	while (!window.Closed()) {
		window.Clear();

		double x, y;
		window.GetMousePosVec(x, y);
		shader.setUniform("light_pos", Vec2d(x * 16.0f / window.GetWidth(), 9.0f - y * 9.0f / window.GetHeight()));

		renderer.Submit(&sprite1);
		renderer.Submit(&sprite2);
		renderer.Submit(&sprite3);
		renderer.Flush(); 

		window.Update();
	}

	return 0;
}