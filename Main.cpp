#include "CImg.h"
using namespace cimg_library;

//�趨��ֵΪ128
const double threshold = 128.0;
int main()
{
	//CImg��ʾҪҪ���ж�ֵ����ͼ�񣬼�ͼ���ڳ����еĶ���ʵ��
	CImg<double> image("gray_oth.bmp");

	//����һ��resultͼ�񣬳���ֱ�Ϊ�򿪵�ͼ��image�ĳ���������ž��������Ķ�ֵͼ��
	CImg<double> result(image.width(),image.height(),1,1,0);

	for (int i = 0 ; i < image.width(); i++)
		for (int j = 0; j < image.height(); j++){
			if (image(i,j,0) < threshold) 
				//����ֵС����ֵ����Ϊ0������ɫ
				result(i,j,0) = 0;
			else
				//����ֵ������ֵ����Ϊ255������ɫ
				result(i,j,0) =255;
		}

	//CImgDiaplay��ʾ������ʾ��ͼ��ʵ��
	CImgDisplay image_disp(image,"Image");
	CImgDisplay result_disp(result,"Result");

	//�ж�����ʾ�����Ƿ�رգ��ر�������˳�������һֱ�ȴ�
	while(!image_disp.is_closed())
		image_disp.wait();

	//���澭����ֵ��������ͼ��
	result.save_bmp("result.bmp");
}
