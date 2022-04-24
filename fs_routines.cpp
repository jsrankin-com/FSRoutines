#include "fs_routines.h"

void copy_file(std::filesystem::path from, std::filesystem::path to)
{
    const auto copyOptions = std::filesystem::copy_options::overwrite_existing;
    std::filesystem::copy_file(from, to, copyOptions);
}

void merge_files(std::vector<std::filesystem::path> p)
{
    std::vector<std::filesystem::path>::iterator it = p.begin();
    ++it;
    std::fstream fpTarget;
    fpTarget.open(p[0], std::fstream::app | std::fstream::out);
    fpTarget << '\n';
    while (it != p.end())
    {
        std::fstream fp;
        fp.open(*it, std::fstream::in);
        char ch;
        while (fp >> std::noskipws >> ch)
            fpTarget << ch;
        fpTarget << '\n';
        ++it;
    }
}

std::string readable_size(std::filesystem::path p)
{
    int i = 0;
    double mantissa = std::filesystem::file_size(p);
    for (; mantissa >= 1024; mantissa /= 1024, ++i) {}

    mantissa = std::ceil(mantissa * 10) / 10;

    std::stringstream ss;
    ss << mantissa << "BKMGTPE"[i];
    return i == 0 
        ? ss.str()
        : (ss << std::filesystem::file_size(p), ss.str());
}
