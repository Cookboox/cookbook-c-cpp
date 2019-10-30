
#include <iostream>
#include <filesystem>
#include <fstream>


//1. Napiš implementaci programu mkdir(vytvoøí adresáø).
void mkdir(const std::filesystem::path &p)
{
	std::filesystem::create_directory(p);
}


//2. Napiš implementaci programu mv (pøesune/pøejmenuje soubor)
void mv(const std::filesystem::path &old_p, const std::filesystem::path &new_p)
{
	std::filesystem::rename(old_p, new_p);
}


//namespace fs = std::filesystem;

int main()
{
	std::filesystem::path current_path = std::filesystem::current_path();

	//create two directories
	std::filesystem::create_directory("my source dir");
	std::filesystem::create_directory("my target dir");

	//attach them to variable names for
	std::filesystem::path source_dir{ current_path/"my source dir" };
	std::filesystem::path target_dir{ current_path/"my target dir" };

	//create files in the source directory
	std::ofstream(current_path / source_dir / "test0.txt");
	std::ofstream(current_path / source_dir / "test1.txt").put('x');
	std::ofstream(current_path / source_dir / "test2.txt").write("hello",6);

	//move one file from the source dir to the taret dir
	std::filesystem::rename(current_path / source_dir / "test2.txt", current_path / target_dir / "test2.txt");
	
	//now move the whole source dir with all its content to the target dir (and change its name to my dir)
	std::filesystem::rename(current_path / source_dir, current_path / target_dir/ "my dir");
	
	std::filesystem::remove(current_path / target_dir / "my dir" / "test0.txt");

	return 0;
}

