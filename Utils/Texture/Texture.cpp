#include "Texture.h"

Texture::Texture(const unsigned int bytes) {


	glTexImage2D(
		GL_TEXTURE_2D, 
		0, 
		GL_RGBA8, 
		nWidth, 
		nHeight,
		0, 
		GL_BGRA, 
		GL_UNSIGNED_BYTE, 
		(void*)bytes
	);
}