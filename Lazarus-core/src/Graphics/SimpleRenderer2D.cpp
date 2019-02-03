#include "SimpleRenderer2D.h"

//Author: Furkan Celik Date: 25.12.2018

namespace Lazarus { namespace Graphics {

	void SimpleRenderer2D::Submit(const Renderable2D* renderable)
	{
		renderQueue.push_back((StaticSprite*)renderable); //adds renderable object to queue for adding it to flush sequence
	}

	void SimpleRenderer2D::Flush()
	{
		while (!renderQueue.empty()) { //until queue became empty
			const StaticSprite* current = renderQueue.front(); //saving front object for reaching values easily. Since this is pointer, this saving wont effect memory
			current->GetVAO()->Bind(); //binding VAO and IBO
			current->GetIBO()->Bind();
			
			current->GetShader().setUniform("mlMatrix", Math::Mat4::translation(current->GetPosition())); //sets mlMatrix value
			glDrawElements(GL_TRIANGLES, current->GetIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr); //draws triangles with given infos. Engine will work based on triangles so all done here is drawing triangle

			current->GetIBO()->Unbind(); //unbinding VAO and IBO
			current->GetVAO()->Unbind();

			renderQueue.pop_front(); //popping front object for iterating to next object in queue
		}
	}

} }