	bool computeFileHash(const EHashAlgorithm algoHash, const QString& filePath, QString& outHexHash)
	{
		if (algoHash == EHashAlgorithm::HashNone) {
			return false;
		}

		QFile file(filePath);
		if (file.exists() && file.open(QIODevice::ReadOnly)) {
			char buffer[SIZE16KB];
			QCryptographicHash digest(detail::get_qt_algo(algoHash));

			auto readLength = file.read(buffer, SIZE16KB);
			while (readLength > 0) {
				digest.addData(buffer, readLength);
				readLength = file.read(buffer, SIZE16KB);
			}
			outHexHash = QString::fromUtf8(digest.result().toHex()).toUpper();
			return true;
		}
		return false;
	}
