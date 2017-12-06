#version 420

gimage3D voxels;

void main()
{
	gl_FragCoord;
	
	
	
	imageStore(voxels, vec3(gl_FragCoord, depth), vec4(1,1,1,1));
}