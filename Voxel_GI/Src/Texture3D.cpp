#include "Texture3D.h"

Texture3D::Texture3D()
{

}

Texture3D::~Texture3D()
{
	UnLoad();
}

void Texture3D::CreateTexture(GLint width, GLint height, GLint depth, GLenum sampleType = GL_LINEAR, bool mipMap = true)
{
	//glGenBuffers(1, &m_Texture);
	//glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_Texture);
	//glBufferData(GL_SHADER_STORAGE_BUFFER, size, NULL, usage);
	//glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, m_Texture);
	//glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);



	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_3D, m_Texture);

	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT); //U axis
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT); //V axis

	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (mipMap)
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	else
		glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB8, width, height, depth, 0, GL_RGB,
		GL_FLOAT, nullptr);

	if (mipMap)
		glGenerateMipmap(GL_TEXTURE_3D);

	return;
}

void Texture3D::Bind()
{
	glBindTexture(GL_TEXTURE_3D, m_Texture);
}

void Texture3D::UnBind()
{
	glBindTexture(GL_TEXTURE_3D, m_Texture);
}

//Delete the current texture
void Texture3D::UnLoad()
{
	if (m_Texture != 0)
	{
		glDeleteTextures(1, &m_Texture);
		m_Texture = 0;
	}
}