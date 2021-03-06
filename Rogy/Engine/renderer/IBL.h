#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <iostream>
#include "shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include "stb_image.h"
#include "RTools.h"
#include "pbr_capture.h"

class IBL
{
public:
	IBL();
	~IBL();

	GLuint captureFBO;
	GLuint captureRBO;

	glm::mat4 captureProjection;
	glm::mat4 captureViews[6];

	GLFWwindow* window = nullptr;

	Shader equirectangularToCubemapShader;
	Shader irradianceShader;
	Shader prefilterShader;
	Shader* brdfShader;

	void Init();

	void LoadHDR(const char* pth, GLuint &envCubemap);

	void CreateCapture(GLuint envMap, PBRCapture &capture, bool removeHDR = false);
	void DeleteCapture(PBRCapture &capture);

	void CreateIrradiance(GLuint envMap, GLuint &irradianceMap, bool removeHDR = false, bool created = false);
	void CreatePreFilter(GLuint envMap, GLuint &prefilterMap, bool removeHDR = false, bool created = false);
	void CreateLUT(GLuint &brdfLUTTexture);

	void ScreenRestore(GLFWwindow *window);

private:

};
