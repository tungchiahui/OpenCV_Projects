#include <cstdio>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/cuda.hpp"


bool Mat_Arr_Split_merge(const std::string &file_name);
bool Vector_Split_merge(const std::string &file_name);

int main(int argc, char ** argv)
{
  (void)argc;
  (void)argv;

  // Mat_Arr_Split_merge("./src/demo3_1_color_space/resources/林星阑L.jpg");
  Vector_Split_merge("./src/demo3_1_color_space/resources/林星阑L.jpg");

  return 0;
}

bool Mat_Arr_Split_merge(const std::string &file_name)
{
  cv::Mat img = cv::imread(file_name);
  if(img.empty() == false)
  {
    printf("成功读取图片!");
  }
  else
  {
    printf("无法读取图片，请确定图片文件是否存在，输入格式是否正确!");
    return false;
  }
  cv::Mat imgs[3];
  cv::Mat result[2];
  cv::split(img,imgs);
  cv::namedWindow("RGB-B通道",cv::WINDOW_FREERATIO);
  cv::namedWindow("RGB-G通道",cv::WINDOW_FREERATIO);
  cv::namedWindow("RGB-R通道",cv::WINDOW_FREERATIO);
  cv::imshow("RGB-B通道",imgs[0]);
  cv::imshow("RGB-G通道",imgs[1]);
  cv::imshow("RGB-R通道",imgs[2]);
  imgs[2] = img;  //改变图像通道数量
  cv::merge(imgs,3,result[0]);
  // cv::namedWindow("合并图像结果0",cv::WINDOW_FREERATIO);
  // cv::imshow("合并图像结果0",result[0]);   //imshow最多显示4个通道，需要Image Watch插件
  cv::Mat zero = cv::Mat::zeros(img.rows,img.cols,CV_8UC1);  //一个通道的0矩阵
  imgs[0] = zero;
  imgs[2] = zero;
  cv::merge(imgs,3,result[1]);
  cv::namedWindow("合并图像结果1",cv::WINDOW_FREERATIO);
  cv::imshow("合并图像结果1",result[1]);   //显示合并结果
  cv::waitKey(0);
  cv::destroyAllWindows();
  return true;
}

bool Vector_Split_merge(const std::string &file_name)
{
  cv::Mat img = cv::imread(file_name);
  if(img.empty() == false)
  {
    printf("成功读取图片!");
  }
  else
  {
    printf("无法读取图片，请确定图片文件是否存在，输入格式是否正确!");
    return false;
  }
  cv::Mat HSV;
  cv::Mat result;
  cv::cvtColor(img,HSV,cv::COLOR_RGB2HSV);
  std::vector<cv::Mat> imgv;
  cv::split(HSV,imgv);
  cv::namedWindow("HSV-H通道",cv::WINDOW_FREERATIO);
  cv::namedWindow("HSV-S通道",cv::WINDOW_FREERATIO);
  cv::namedWindow("HSV-V通道",cv::WINDOW_FREERATIO);
  cv::imshow("HSV-H通道",imgv.at(0));
  cv::imshow("HSV-S通道",imgv.at(1));
  cv::imshow("HSV-V通道",imgv.at(2));
  imgv.push_back(HSV);  //将imgv中的图像通道变成不一致
  cv::merge(imgv,result);
  // cv::namedWindow("合并图像结果2",cv::WINDOW_FREERATIO);
  // cv::imshow("合并图像结果2",result);   //imshow最多显示4个通道，需要Image Watch插件
  cv::waitKey(0);
  cv::destroyAllWindows();
  return true;
}
