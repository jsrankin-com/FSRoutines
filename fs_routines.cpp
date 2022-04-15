#include "fs_routines.h"

void copy_file(std::filesystem::path from, std::filesystem::path to)
{
    const auto copyOptions = std::filesystem::copy_options::overwrite_existing;
    std::filesystem::copy_file(from, to, copyOptions);
}
