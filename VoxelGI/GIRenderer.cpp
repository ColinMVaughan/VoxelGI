#include "GIRenderer.h"

GIRenderer::GIRenderer()
	:m_FinalFrame(1)
{
}

void GIRenderer::Initalize()
{
	if (!m_VoxelizationShader.Load("", "", ""))
		std::cout << "Could not Load Voxelization Shader";
}

void GIRenderer::PreRender()
{
}

void GIRenderer::VoxelizeMesh(Mesh * a_mesh, Material * material, float * ModelMatrix)
{
}


void GIRenderer::PostRender()
{
}
