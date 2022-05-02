// #include<torch/torch.h>
// #include<torch/script.h>
// #include<opencv2/opencv.hpp>
// #include<iostream>
// #include "TorchModule.h"
// int main()
// {
// 	TorchModule test("model\\74.3%_12_6piece_512.pt");
// 	test.setLabel({ "Aya","Cirno","Flandre","Koishi","Marisa","Reimu","Reisen","Remilia","Sanae","Satori","Suwako","Youmu" });
// 	test.setImg(R"(F:\code\work\TouhouCharacterFigure\TorchModule\testImg\1650963747337.jpg)");
// 	auto ans = test.FigureSingleImg();
// 	for (auto i : ans)
// 	{
// 		printf("%s : %lf\n", i.first.c_str(), i.second);
// 	}
// 	test.classifyImgs(R"(F:\code\work\TouhouCharacterFigure\TorchModule\testImg\)", R"(F:\code\work\TouhouCharacterFigure\TorchModule\testImg\out)");
// 	return 0;
// 	// torch::Device deviceCuda("cuda");
// 	// torch::jit::Module modulee;
// 	// try
// 	// {
// 	// 	modulee = torch::jit::load("model\\75.4%_12_6piece_512.pt");
// 	// 	modulee.to(deviceCuda);
// 	// }
// 	// catch (const c10::Error& e)
// 	// {
// 	// 	std::cerr << "error loading the model\n";
// 	// 	return -1;
// 	// }
// 	// cv::Mat img = cv::imread("F:\\za\\エイセイパレード_109951164079708306.png");
// 	// cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
// 	// cv::Mat imgFloat;
// 	// img.convertTo(imgFloat, CV_32F, 1.0 / 255);
// 	// cv::resize(imgFloat, imgFloat, cv::Size(512, 512));
// 	// auto imgTensor = torch::from_blob(imgFloat.data, { 1,512,512,3 }, torch::kFloat32).cuda();
// 	// imgTensor = imgTensor.permute({ 0,3,1,2 });
// 	// imgTensor[0][0] = imgTensor[0][0].sub_(0.485).div_(0.229);
// 	// imgTensor[0][1] = imgTensor[0][1].sub_(0.456).div_(0.224);
// 	// imgTensor[0][2] = imgTensor[0][2].sub_(0.406).div_(0.225);
// 	// std::vector<torch::jit::IValue>inputs2;
// 	// inputs2.push_back(imgTensor);
// 	// at::Tensor outputs = modulee.forward(inputs2).toTensor();
// 	// //std::cout << outputs.sizes() << std::endl;
// 	// //std::cout << outputs << std::endl;
// 	// std::string label12[] = { "Aya","Cirno","Flandre","Koishi","Marisa","Reimu","Reisen","Remilia","Sanae","Satori","Suwako","Youmu" };
// 	// std::tuple<torch::Tensor, torch::Tensor> result = outputs.sort(-1, true);
// 	// torch::Tensor scoresTensor = std::get<0>(result)[0];
// 	// torch::Tensor idxsTensor = std::get<1>(result)[0].toType(torch::kInt32);
// 	// scoresTensor = torch::softmax(scoresTensor, -1) * 100;
// 	// //scoresTensor=scoresTensor.cpu();
// 	// //idxsTensor = idxsTensor.cpu();
// 	// //auto scores = scoresTensor.accessor<float, 1>();
// 	// //auto idxs = idxsTensor.generic_packed_accessor<int, 1>();
// 	// //std::cout << scoresTensor.dim() << "  " << scoresTensor << std::endl;
// 	// for (int i = 0; i < 12; ++i)
// 	// {
// 	// 	auto idx = idxsTensor[i].item().toInt();
// 	// 	std::printf("%s:%f%%\n", label12[idx].c_str(), scoresTensor[i].item().toFloat());
// 	// }
// 	// return 0;
// }