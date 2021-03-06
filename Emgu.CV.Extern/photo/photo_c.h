//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2015 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_PHOTO_C_H
#define EMGU_PHOTO_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/photo/photo.hpp"

#include "opencv2/photo/cuda.hpp"

CVAPI(void) cveInpaint( cv::_InputArray* src, cv::_InputArray* inpaintMask, cv::_OutputArray* dst, double inpaintRadius, int flags );

CVAPI(void) cveFastNlMeansDenoising(cv::_InputArray* src, cv::_OutputArray* dst, float h, int templateWindowSize, int searchWindowSize);

CVAPI(void) cveFastNlMeansDenoisingColored(cv::_InputArray* src, cv::_OutputArray* dst, float h, float hColor, int templateWindowSize, int searchWindowSize);

CVAPI(void) cudaNonLocalMeans(const cv::cuda::GpuMat* src, cv::cuda::GpuMat* dst, float h, int searchWindow, int blockSize, int borderMode, cv::cuda::Stream* stream);

CVAPI(void) cveEdgePreservingFilter(cv::_InputArray* src, cv::_OutputArray* dst, int flags, float sigmaS, float sigmaR);

CVAPI(void) cveDetailEnhance(cv::_InputArray* src, cv::_OutputArray* dst, float sigmaS, float sigmaR);

CVAPI(void) cvePencilSketch(cv::_InputArray* src, cv::_OutputArray* dst1, cv::_OutputArray* dst2, float sigmaS, float sigmaR, float shadeFactor);

CVAPI(void) cveStylization(cv::_InputArray* src, cv::_OutputArray* dst, float sigmaS, float sigmaR);

CVAPI(void) cveColorChange(cv::_InputArray* src, cv::_InputArray* mask, cv::_OutputArray* dst, float redMul, float greenMul, float blueMul);

CVAPI(void) cveIlluminationChange(cv::_InputArray* src, cv::_InputArray* mask, cv::_OutputArray* dst, float alpha, float beta);

CVAPI(void) cveTextureFlattening(cv::_InputArray* src, cv::_InputArray* mask, cv::_OutputArray* dst, float lowThreshold, float highThreshold, int kernelSize);


CVAPI(void) cveCalibrateCRFProcess(cv::CalibrateCRF* calibrateCRF, cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* times);

CVAPI(cv::CalibrateDebevec*) cveCreateCalibrateDebevec(int samples, float lambda, bool random, cv::CalibrateCRF** calibrateCRF);

CVAPI(cv::CalibrateRobertson*) cveCreateCalibrateRobertson(int max_iter, float threshold, cv::CalibrateCRF** calibrateCRF);

CVAPI(void) cveMergeExposuresProcess(
   cv::MergeExposures* mergeExposures, 
   cv::_InputArray* src, cv::_OutputArray* dst,
   cv::_InputArray* times, cv::_InputArray* response);

CVAPI(cv::MergeDebevec*) cveCreateMergeDebevec(cv::MergeExposures** merge);
CVAPI(void) cveMergeDebevecRelease(cv::MergeDebevec** merge);

CVAPI(cv::MergeMertens*) cveCreateMergeMertens(float contrast_weight, float saturation_weight, float exposure_weight, cv::MergeExposures** merge);
CVAPI(void) cveMergeMertensRelease(cv::MergeMertens** merge);

CVAPI(cv::MergeRobertson*) cveCreateMergeRobertson(cv::MergeExposures** merge);
CVAPI(void) cveMergeRobertsonRelease(cv::MergeRobertson** merge);

CVAPI(void) cveDenoiseTVL1(const std::vector< cv::Mat >* observations, cv::Mat* result, double lambda, int niters);
#endif