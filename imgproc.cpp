#include "imgproc.h"

void CvtColor(Mat src, Mat dst, int code) {
    cv::cvtColor(*src, *dst, code);
}

void Blur(Mat src, Mat dst, Size ps) {
    cv::Size sz(ps.width, ps.height);
    cv::blur(*src, *dst, sz);    
}

void GaussianBlur(Mat src, Mat dst, Size ps, double sX, double sY, int bt) {
    cv::Size sz(ps.width, ps.height);
    cv::GaussianBlur(*src, *dst, sz, sX, sY, bt);
}

void Canny(Mat src, Mat edges, double t1, double t2) {
    cv::Canny(*src, *edges, t1, t2);
}

void HoughLines(Mat src, Mat lines, double rho, double theta, int threshold) {
    cv::HoughLines(*src, *lines, rho, theta, threshold);
}

void HoughLinesP(Mat src, Mat lines, double rho, double theta, int threshold) {
    cv::HoughLinesP(*src, *lines, rho, theta, threshold);
}

void Rectangle(Mat img, Rect r, Scalar color, int thickness) {
    cv::Scalar c = cv::Scalar(color.val1, color.val2, color.val3, color.val4);
    cv::rectangle(*img, cv::Point(r.x, r.y), cv::Point(r.x+r.width, r.y+r.height),
        c, thickness, CV_AA);
}

struct Size GetTextSize(const char* text, int fontFace, double fontScale, int thickness) {
    cv::Size sz = cv::getTextSize(text, fontFace, fontScale, thickness, NULL);
    Size size = {sz.width, sz.height};
    return size;
}

void PutText(Mat img, const char* text, Point org, int fontFace, double fontScale, 
    Scalar color, int thickness) {
    cv::Point pt(org.x, org.y);
    cv::Scalar c = cv::Scalar(color.val1, color.val2, color.val3, color.val4);
    cv::putText(*img, text, pt, fontFace, fontScale, c, thickness);
}
