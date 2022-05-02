#include "TorchModule.h"
#include <string>
#include "torch/torch.h"
#include "opencv2/opencv.hpp"
#include "torch/script.h"
TorchModule::TorchModule(const std::string ModuleRoute) : device{ "cuda" }, label{}, img{}, module(ModuleRoute)
{
	auto moduleLoad = torch::jit::load(ModuleRoute);
	moduleLoad.eval();
}

TorchModule::TorchModule() : device{ "cuda" } {}

void TorchModule::setModule(std::string moduleRoute)
{
	auto moduleLoad = torch::jit::load(moduleRoute);
	moduleLoad.eval();
	module = moduleRoute;
}


void TorchModule::setImg(const std::string ImgRoute)
{
	img = ImgRoute;
}

void TorchModule::setLabel(std::vector<std::string> inputLable)
{
	label = inputLable;
}

void TorchModule::setImgsFolderRoute(std::string Route)
{
	imgFolderRoute = Route;
}

std::vector<std::pair<std::string, double>> TorchModule::FigureSingleImg()
{

	if (label.empty())return {};
	cv::Mat imgtemp, imgNow = cv::imread(img);
	torch::Device(device.c_str());
	auto moduleLoad = torch::jit::load(module);
	moduleLoad.eval();
	cv::cvtColor(imgNow, imgtemp, cv::COLOR_BGR2RGB);
	cv::Mat imgFloat;
	imgtemp.convertTo(imgFloat, CV_32F, 1.0 / 255);
	cv::resize(imgFloat, imgFloat, cv::Size(512, 512));
	auto imgTensor = torch::from_blob(imgFloat.data, { 1,512,512,3 }, torch::kFloat32).cuda();
	imgTensor = imgTensor.permute({ 0,3,1,2 });
	imgTensor[0][0] = imgTensor[0][0].sub_(0.485).div_(0.229);
	imgTensor[0][1] = imgTensor[0][1].sub_(0.456).div_(0.224);
	imgTensor[0][2] = imgTensor[0][2].sub_(0.406).div_(0.225);
	std::vector<torch::jit::IValue>inputs2;
	inputs2.push_back(imgTensor);
	at::Tensor outputs = moduleLoad.forward(inputs2).toTensor();
	//std::cout << outputs.sizes() << std::endl;
	//std::cout << outputs << std::endl;
	// std::string label12[] = { "Aya","Cirno","Flandre","Koishi","Marisa","Reimu","Reisen","Remilia","Sanae","Satori","Suwako","Youmu" };
	std::tuple<torch::Tensor, torch::Tensor> result = outputs.sort(-1, true);
	torch::Tensor scoresTensor = std::get<0>(result)[0];
	torch::Tensor idxsTensor = std::get<1>(result)[0].toType(torch::kInt32);
	scoresTensor = torch::softmax(scoresTensor, -1) * 100;
	std::vector<std::pair<std::string, double>>ans{};
	for (int i = 0; i < 12; ++i)
	{
		auto idx = idxsTensor[i].item().toInt();
		// std::printf("%s:%f%%\n", label12[idx].c_str(), scoresTensor[i].item().toFloat());
		ans.push_back(std::make_pair(label[idx].c_str(), scoresTensor[i].item().toDouble()));
	}
	return ans;

}

void TorchModule::classifyImgs(std::string imgsRoute, std::string outPutRoute)
{
	cv::String inputRoute(imgsRoute);
	std::vector<cv::String>imgs, temp{};
	cv::glob(inputRoute + "\\*.jpg", imgs, false);
	cv::glob(inputRoute + "\\*.png", temp, false);
	imgs.insert(imgs.end(), temp.begin(), temp.end());
	temp.clear();
	for (auto i : label)system(("mkdir " + outPutRoute + "\\" + i).c_str());
	for (auto& imgRoute : imgs)
	{
		setImg(imgRoute);
		auto ans = FigureSingleImg();
		std::string chara = ans[0].first;
		std::string imgName = imgRoute.substr(imgRoute.find_last_of('\\') + 1);
		// std::cout << outPutRoute + "\\" + ans[0].first + "\\" + imgName;
		cv::imwrite(outPutRoute + "\\" + chara + "\\" + imgName, cv::imread(img));
	}
}

void TorchModule::setLabel(std::string labelFileName)
{
	label.clear();
	std::string singleLabel{};
	std::ifstream f(fopen(labelFileName.c_str(), "r"));
	while (std::getline(f, singleLabel).good())
		label.push_back(singleLabel);
	if (singleLabel[0] != '\n' || !singleLabel.empty())label.push_back(singleLabel);
}
