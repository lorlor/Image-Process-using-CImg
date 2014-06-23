#include "CImg.h"
using namespace cimg_library;

//设定阈值为128
const double threshold = 128.0;
int main()
{
	//CImg表示要要进行二值化的图像，即图像在程序中的对象实例
	CImg<double> image("gray_oth.bmp");

	//定义一个result图像，长宽分别为打开的图像image的长宽，用来存放经过处理后的二值图像
	CImg<double> result(image.width(),image.height(),1,1,0);

	for (int i = 0 ; i < image.width(); i++)
		for (int j = 0; j < image.height(); j++){
			if (image(i,j,0) < threshold) 
				//像素值小于阈值的置为0，即黑色
				result(i,j,0) = 0;
			else
				//像素值大于阈值的置为255，即白色
				result(i,j,0) =255;
		}

	//CImgDiaplay表示用来显示的图像实例
	CImgDisplay image_disp(image,"Image");
	CImgDisplay result_disp(result,"Result");

	//判断主显示窗口是否关闭，关闭则程序退出，否则一直等待
	while(!image_disp.is_closed())
		image_disp.wait();

	//保存经过二值化处理后的图像
	result.save_bmp("result.bmp");
}
