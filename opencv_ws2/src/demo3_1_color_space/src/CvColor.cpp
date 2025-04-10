#include <iostream>
#include <ostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/core/cuda.hpp"

int main(int argc, char ** argv)
{
  (void)argc;
  (void)argv;

  const std::string & file_name = "./src/demo3_1_color_space/resources/林星阑L.jpg";

  cv::Mat img = cv::imread(file_name);
  if(img.empty() == true)
  {
      std::cout << "请确认图像文件是否正确，请检查输入格式" << std::endl;
      return 1;
  }
  else
  {
      std::cout << "图像成功读取!" << std::endl;
  }
  cv::Mat img32;
  cv::Mat gray,HSV,YUV,Lab;
  img.convertTo(img32,CV_32F,1.0/255);   //缩放因子:1.0/255指将现在的图像的范围转换为目标图像的范围需要乘以的因数
  cv::cvtColor(img32,HSV,cv::COLOR_BGR2HSV);
  cv::cvtColor(img32,YUV,cv::COLOR_BGR2YUV);
  cv::cvtColor(img32,Lab,cv::COLOR_BGR2Lab);
  cv::cvtColor(img32,gray,cv::COLOR_BGR2GRAY);

  cv::namedWindow("原图BGR",cv::WINDOW_FREERATIO);
  cv::namedWindow("HSV",cv::WINDOW_FREERATIO);
  cv::namedWindow("YUV",cv::WINDOW_FREERATIO);
  cv::namedWindow("Lab",cv::WINDOW_FREERATIO);
  cv::namedWindow("gray",cv::WINDOW_FREERATIO);
  cv::imshow("原图BGR",img32);
  cv::imshow("HSV",HSV);
  cv::imshow("YUV",YUV);
  cv::imshow("Lab",Lab);
  cv::imshow("gray",gray);
  cv::waitKey(0);

  return 0;
}

