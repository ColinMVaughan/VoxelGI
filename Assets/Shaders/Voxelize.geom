#version 420

layout (triangles) in;
layout (triangles, max_vertices = 3) out;

uniform  mat4 ViewProjX;

void main()
{
	vec3 normal;
	float axisValue[3];
	
	//Calculate normal of triangle
	
	//Determine which axis is most parralell with normal
	axisValue[0] = abs(dot(normal, vec3(1,0,0)));
	axisValue[2] = abs(dot(normal, vec3(0,1,0)));
	axisValue[3] = abs(dot(normal, vec3(0,0,1)));
	
	//Select a projection based on which axis is most dominant
	if(axisValue[0] > axisValue[1] && axisValue[0] > axisvalue[2])
	{
	
	}
	else if(axisValue[1] > axisValue[0] && axisValue[1] > axisvalue[2])
	{
	
	}
	else
	{
	
	}

}