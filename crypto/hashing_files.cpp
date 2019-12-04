std::string calculateFileHash(const fs::path& pathToAnalyzedFile)
	{
		size_t fileLength{};
		std::string fileContent{};

		std::ifstream inputFile(pathToAnalyzedFile, std::ifstream::binary | std::ifstream::in);
		if (!inputFile) {
			return false;
		} else {
			inputFile.seekg(0, inputFile.end);
			fileLength = inputFile.tellg();
			fileContent.reserve(fileLength);
			fileContent.assign((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>())); 
			inputFile.close();
		}
		unsigned char hash[SHA256_DIGEST_LENGTH];
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256, fileContent.c_str(), fileContent.size());
		SHA256_Final(hash, &sha256);

		std::stringstream ss{};
		for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
			ss << std::hex << static_cast<int>(hash[i]);
		}
		return ss.str();
	}
