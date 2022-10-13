#pragma once
#ifndef COMPARISON_H
#define COMPARISON_H

#include <vector>

int min(int a, int b);
int max(int a, int b);
std::vector<int> min(std::vector<int> a, std::vector<int> b);
std::vector<int> max(std::vector<int> a, std::vector<int> b);
bool IsDifferent(std::vector<int> a, std::vector<int> b);

#endif