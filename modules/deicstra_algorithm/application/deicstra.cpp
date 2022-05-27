// Copyright 2022 Zaitseva Ksenia

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING 1

#include <iostream>
#include <string>

#include "include/deicstra_application.h"

int main(int argc, const char** argv) {
  DeicstraApplication app;
  std::string output = app(argc, argv);
  std::cout << output;
  return 0;
}
