#pragma once
#include <FrameBuffer.h>
#include <Renderer.h>
#include "Texture3D.h"


class GIRenderer
{
public:
	GIRenderer();

	void Initalize()
	{
		glEnable(GL_TEXTURE_3D);
		m_VoxelBuffer.CreateTexture(128, 128, 128, GL_LINEAR, false);
		m_VoxelizationShader.Load("./Assets/Shaders/Voxeliaztion.vert",
			"./Assets/Shaders/Voxelization.geom",
			"./Assets/Shaders/Voxelization.frag");
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