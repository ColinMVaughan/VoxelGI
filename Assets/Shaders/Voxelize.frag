#version 420

gimage3D voxels;

void main()
{
	imageStore(voxels, gl_FragCoord.xyz, vec4(1,1,1,1));
}