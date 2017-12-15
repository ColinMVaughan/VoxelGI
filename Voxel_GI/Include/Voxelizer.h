#pragma once
#include <FrameBuffer.h>
#include <Renderer.h>
#include "Texture3D.h"

//-----------------------------------------
//
//-----------------------------------------
class Voxelizer
{
public:
	Voxelizer();

	void Initalize();

	void PreRender();
	void VoxelizeMesh(Mesh* a_mesh, Material* material, float* ModelMatrix);
	void PostRender();


	Texture3D& GetVoxelBuffer();

private:

	Texture3D m_VoxelBuffer;
	ShaderProgram m_VoxelizationShader;
	FrameBuffer m_FinalFrame;
	Camera m_Camera;
};