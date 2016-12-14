#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	// set google glog
	{
		google::InitGoogleLogging("LogFileName");
		// 0: log to file; 1: log to std io
		FLAGS_logtostderr = 1;
		FLAGS_logbuflevel = 1;
		google::SetLogDestination(0, "./LOG.");
	}

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}
