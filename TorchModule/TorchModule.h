#ifndef _TORCHMODULE_
#define _TORCHMODULE_

#ifdef _EXPORTING  
#define API_DECLSPEC    __declspec(dllexport)  
#else  
#define API_DECLSPEC    __declspec(dllimport)  
#endif  
#include<string>
#include <vector>
class API_DECLSPEC TorchModule
{
private:
	std::string module;
	std::string device;
	// cv::Mat img;
	std::string img;
	std::vector<std::string>label;
	// cv::String imgFolderRoute;
	std::string imgFolderRoute;
public:
	TorchModule(const std::string ModuleRoute);
	TorchModule();

	void setImg(const std::string ImgRoute);
	std::vector<std::pair<std::string, double>>FigureSingleImg();
	void setLabel(std::vector<std::string>inputLable);
	void setLabel(std::string labelFileName);

	void setImgsFolderRoute(std::string in);

	void classifyImgs(std::string imgsRoute, std::string outPutRoute);

	void setModule(std::string moduleRoute);
};

#endif //_TORCHMODULE_