#ifndef KDM_SRC_LIBRARY_FILE_READ_WRITE_H
#define KDM_SRC_LIBRARY_FILE_READ_WRITE_H

#include <fstream>

typedef struct SKDMFile{
	char* m_szFileName = 0;
	int m_nFileSize = -1;
	char* m_tRawData = 0;
}SKDMFile;


class CKDMFileRead{
public:
	CKDMFileRead(char* p_szFileName){ open(p_szFileName); }
	~CKDMFileRead(){ close(); }

	void open(char* p_szFileName);
	void close();

	inline bool isOpen(){ return this->m_inputStream.is_open(); }
	inline std::ifstream* getStream(){ return &(this->m_inputStream); }
	inline const char* getFileName() const { return this->m_file.m_szFileName; }
	inline const int getFileSize() const { return this->m_file.m_nFileSize; }

	//주어진 배열에 복사도 하고, 서비스로 그거 리턴도 해줌;
	char* getData(char* p_tDest, int p_iStart, int p_iSize);
	char* getRawData(){ return this->readAll(); }
		
	char* operator()(char* p_tDest, int p_iStart, int p_iSize){	return this->getData(p_tDest, p_iStart, p_iSize); }
	char* operator()(){ return this->getRawData(); }

private:
	char* readAll();
	char* readRange(char* p_tDest, int p_iStart, int p_iSize);

	std::ifstream m_inputStream;
	SKDMFile m_file;
};

#endif KDM_SRC_LIBRARY_FILE_READ_WRITE_H