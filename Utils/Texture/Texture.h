class Texture {
	public:
		Texture();
		~Texture();
		//
		void bind();
	private:
		unsigned int textureId;
};