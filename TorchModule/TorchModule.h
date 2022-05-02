#pragma once
#include "torch/torch.h"
#include<torch/script.h>
#include<cstring>
#include <vector>
#include<opencv2/opencv.hpp>
class TorchModule
{
private:
	torch::jit::Module module;
	torch::Device device;
	cv::Mat img;
	std::vector<std::string>label;
	cv::String imgFolderRoute;
public:
	TorchModule(const std::string ModuleRoute);
	TorchModule();

	void setImg(const std::string ImgRoute);
	std::vector<std::pair<std::string, double>>FigureSingleImg();
	void setLabel(std::vector<std::string>inputLable);
	void setLabel(std::string labelFileName);

	void setImgsFolderRoute(std::string in);

	void classifyImgs(std::string imgsRoute, std::string outPutRoute);
};

