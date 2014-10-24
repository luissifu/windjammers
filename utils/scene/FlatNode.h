#pragma once
#include "SceneNode.h"
#include "../texture/Texture.h"

class FlatNode : public SceneNode {
	public:
		FlatNode();
		void setTexture(Texture t);
		Texture getTexture();
		void setSize(int w, int h);
		int getWidth();
		int getHeight();
	private:
		Texture texture;
		int width;
		int height;
};
