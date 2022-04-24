#pragma once
#include <iostream>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>

void copy_file(std::filesystem::path, std::filesystem::path);

void merge_files(std::vector<std::filesystem::path>);

std::string readable_size(std::filesystem::path);
