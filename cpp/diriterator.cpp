
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
    string dirName;
    cout << "Enter the directory name: ";
    cin >> dirName;
    for (auto &p : fs::recursive_directory_iterator(dirName))
    {
        std::cout << p.path() << '\n';
    }
}