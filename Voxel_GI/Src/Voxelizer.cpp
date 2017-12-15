#include "GIRenderer.h"

Voxelizer::Voxelizer()
	:m_FinalFrame(1)
{
}

//Create the 3DTexture buffer to store the voxelized scene
void Voxelizer::Initalize()
{
	glEnable(GL_TEXTURE_3D);
	m_VoxelBuffer.CreateTexture(128, 128, 128, GL_LINEAR, false);
	m_VoxelizationShader.Load("./Assets/Shaders/Voxeliaztion.vert",
		"./Assets/Shaders/Voxelization.geom",
		"./Assets/Shaders/Voxelization.frag");
}


void Voxelizer::PreRender()
{
	//disable framebuffer operations because we are modifying a 3d texture,
	//not rendering to framebuffer
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

}

Texture3D& Voxelizer::GetVoxelBuffer()
{
	return m_VoxelBuffer;
}