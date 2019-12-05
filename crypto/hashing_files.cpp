	std::string calculateFileHash(const fs::path& pathToAnalyzedFile)
	{
		std::ifstream inputFile(pathToAnalyzedFile, std::ifstream::binary | std::ifstream::in);
		if (!inputFile) {
			return false;
		}

		constexpr const std::size_t buffer_size{ 16384 };
		char buffer[buffer_size];
		unsigned char hash[SHA256_DIGEST_LENGTH];

		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		
		while (inputFile.good()) {
			inputFile.read(buffer, buffer_size);
			SHA256_Update(&sha256, buffer, inputFile.gcount());
		}

		SHA256_Final(hash, &sha256);

		std::stringstream ss{};
		for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
			ss << std::hex << static_cast<int>(hash[i]);
		}
		return ss.str();
	}
