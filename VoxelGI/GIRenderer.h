#pragma once
#include <GLRenderer\FrameBuffer.h>
#include <GLRenderer\Renderer.h>
#include "Texture3D.h"

class GIRenderer
{
public:
	GIRenderer();

	void Initalize()
	{
		glEnable(GL_TEXTURE_3D);

	}

	void PreRender()
	{
		//disable framebuffer operations because we are modifying a 3d texture,
		//not rendering to framebuffer
		glDisable(GL_DEPTH_TEST);
		glDepthMask(GL_FALSE);
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

	}
	void VoxelizeMesh(Mesh* a_mesh, Material* material, float* ModelMatrix);
	void PostRender();

private:


	Texture3D m_VoxelBuffer;
	ShaderProgram m_VoxelizationShader;
	FrameBuffer m_FinalFrame;
	Camera m_Camera;
};