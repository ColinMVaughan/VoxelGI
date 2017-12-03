#pragma once
#include <GLRenderer\FrameBuffer.h>
#include <GLRenderer\Renderer.h>

class GIRenderer
{
public:
	GIRenderer();

	void PreRender();
	void RenderMesh(Mesh* a_mesh, Material* material, float* ModelMatrix);
	void PostRender();

private:
	FrameBuffer m_FinalFrame;
	Camera m_Camera;
};