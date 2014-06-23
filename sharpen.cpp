#include "CImg.h"
#include <cmath>
using namespace cimg_library;

/**********************************
* 下述六个掩膜矩阵从上之下，依次对应文中的
* a,b,c,d,e,f六个掩膜矩阵
***********************************/
const int lap_a[3][3] = {{0,1,0},{1,-4,1},{0,1,0}};
const int lap_b[3][3] = {{1,1,1},{1,-8,1},{1,1,1}};
const int lap_c[3][3] = {{0,-1,0},{-1,4,-1},{0,-1,0}};
const int lap_d[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
const int lap_e[3][3] = {{0,-1,0},{-1,5,-1},{0,-1,0}};
const int lap_f[3][3] = {{-1,-1,-1},{-1,5,-1},{-1,-1,-1}};

int main()
{
	//image表示将要进行处理的图像文件，即外部图像文件在程序中的实例
	CImg<double> image("gray_oth.bmp");
	/******************************************************
	* lap*_image表示CImg实例，稍后将用来保存经过处理后的图像实例，
	* 此处的*代表a,b,c,d,e,f
	*******************************************************/
	CImg<double> lapa_image(image.width(),image.height(),1,1,0);
	CImg<double> lapb_image(image.width(),image.height(),1,1,0);
	CImg<double> lapc_image(image.width(),image.height(),1,1,0);
	CImg<double> lapd_image(image.width(),image.height(),1,1,0);
	CImg<double> lape_image(image.width(),image.height(),1,1,0);
	CImg<double> lapf_image(image.width(),image.height(),1,1,0);
	
	//将掩膜矩阵a作用于图像，结果保存在lapa_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_a[0][0] * image(i-1,j-1,0) + lap_a[0][1] * image(i-1,j,0) + lap_a[0][2] * image(i-1,j+1,0) +
						  lap_a[1][0] * image(i,j-1,0) + lap_a[1][1] * image(i,j,0) + lap_a[1][2] * image(i,j+1,0) + 
						  lap_a[2][0] * image(i+1,j-1,0) + lap_a[2][1] * image(i+1,j,0) +lap_a[2][2] * image(i+1,j+1,0);
			lapa_image(i,j,0) = abs(temp);
		}

	//将掩膜矩阵b作用于图像，结果保存在lapb_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_b[0][0] * image(i-1,j-1,0) + lap_b[0][1] * image(i-1,j,0) + lap_b[0][2] * image(i-1,j+1,0) +
						  lap_b[1][0] * image(i,j-1,0) + lap_b[1][1] * image(i,j,0) + lap_b[1][2] * image(i,j+1,0) + 
						  lap_b[2][0] * image(i+1,j-1,0) + lap_b[2][1] * image(i+1,j,0) +lap_b[2][2] * image(i+1,j+1,0);
			lapb_image(i,j,0) = abs(temp);
		}

	//将掩膜矩阵c作用于图像，结果保存在lapc_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_c[0][0] * image(i-1,j-1,0) + lap_c[0][1] * image(i-1,j,0) + lap_c[0][2] * image(i-1,j+1,0) +
						  lap_c[1][0] * image(i,j-1,0) + lap_c[1][1] * image(i,j,0) + lap_c[1][2] * image(i,j+1,0) + 
						  lap_c[2][0] * image(i+1,j-1,0) + lap_c[2][1] * image(i+1,j,0) +lap_c[2][2] * image(i+1,j+1,0);
			lapc_image(i,j,0) = abs(temp);
		}

	//将掩膜矩阵d作用于图像，结果保存在lapd_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_d[0][0] * image(i-1,j-1,0) + lap_d[0][1] * image(i-1,j,0) + lap_d[0][2] * image(i-1,j+1,0) +
						  lap_d[1][0] * image(i,j-1,0) + lap_d[1][1] * image(i,j,0) + lap_d[1][2] * image(i,j+1,0) + 
						  lap_d[2][0] * image(i+1,j-1,0) + lap_d[2][1] * image(i+1,j,0) +lap_d[2][2] * image(i+1,j+1,0);
			lapd_image(i,j,0) = abs(temp);
		}

	//将掩膜矩阵e作用于图像，结果保存在lape_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_e[0][0] * image(i-1,j-1,0) + lap_e[0][1] * image(i-1,j,0) + lap_e[0][2] * image(i-1,j+1,0) +
						  lap_e[1][0] * image(i,j-1,0) + lap_e[1][1] * image(i,j,0) + lap_e[1][2] * image(i,j+1,0) + 
						  lap_e[2][0] * image(i+1,j-1,0) + lap_e[2][1] * image(i+1,j,0) +lap_e[2][2] * image(i+1,j+1,0);
			lape_image(i,j,0) = abs(temp);
		}

	//将掩膜矩阵f作用于图像，结果保存在lapf_image中
	for (int i = 1; i < image.width(); i++) 
		for (int j = 1; j < image.height(); j++){
			double temp = lap_f[0][0] * image(i-1,j-1,0) + lap_f[0][1] * image(i-1,j,0) + lap_f[0][2] * image(i-1,j+1,0) +
						  lap_f[1][0] * image(i,j-1,0) + lap_f[1][1] * image(i,j,0) + lap_f[1][2] * image(i,j+1,0) + 
						  lap_f[2][0] * image(i+1,j-1,0) + lap_f[2][1] * image(i+1,j,0) +lap_f[2][2] * image(i+1,j+1,0);
			lapf_image(i,j,0) = abs(temp);
		}

	//下述语句意为显示经过处理后的六幅图像以及原始图像
	CImgDisplay image_disp(image,"Image");							
	CImgDisplay lapa_image_disp(lapa_image,"Lapa_Image");			
	CImgDisplay lapb_image_disp(lapb_image,"Lapb_Image");			
	CImgDisplay lapc_image_disp(lapc_image,"Lapc_Image");			
	CImgDisplay lapd_image_disp(lapd_image,"Lapd_Image");			
	CImgDisplay lape_image_disp(lape_image,"Lape_Image");			
	CImgDisplay lapf_image_disp(lapf_image,"Lapf_Image");			

	while(!image_disp.is_closed())
		image_disp.wait();

	//保存经过处理后的图像
	lapa_image.save_bmp("lapa.bmp");
	lapb_image.save_bmp("lapb.bmp");
	lapc_image.save_bmp("lapc.bmp");
	lapd_image.save_bmp("lapd.bmp");
	lape_image.save_bmp("lape.bmp");
	lapf_image.save_bmp("lapf.bmp");

	return 0;
}