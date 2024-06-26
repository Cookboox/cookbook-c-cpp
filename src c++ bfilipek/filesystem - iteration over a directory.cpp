#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

fs::path p{ fs::current_path() };

void DisplayDirectoryTree(const fs::path& pathToScan, int level = 0)
{
	for (const auto& entry : fs::directory_iterator(pathToScan)) {
		const auto filenameStr = entry.path().filename().string();
		if (entry.is_directory()) {
			std::cout << std::setw(level * 3) << "" << filenameStr << '\n';
			DisplayDirectoryTree(entry, level + 1);
		}
		else if (entry.is_regular_file()) {
			std::cout << std::setw(level * 3) << "" << filenameStr
				<< ", size " << entry.file_size() << " bytes\n";
		}
		else
			std::cout << std::setw(level * 3) << "" << " [?]" << filenameStr << '\n';
	}
}

int main()
{
	DisplayDirectoryTree(p);



}