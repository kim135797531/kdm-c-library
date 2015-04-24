#ifndef KDM_SRC_LIBRARY_FILE_READ_WRITE_H
#define KDM_SRC_LIBRARY_FILE_READ_WRITE_H

#include <fstream>

typedef struct SKDMFile{
	char* m_szFileName = 0;
	int m_nFileSize = -1;
	char* m_szRawData = 0;
}SKDMFile;

//데이터 보호를 위해 읽기만 가능하다.
class CKDMFileRead{
public:
	CKDMFileRead(const char* p_szFileName){ open(p_szFileName); }
	~CKDMFileRead(){ close(); }

	void open(const char* p_szFileName);
	void close();

	inline bool isOpen() const { return this->m_inputStream.is_open(); }
	inline std::ifstream* getStream(){ return &(this->m_inputStream); }
	inline const char* getFileName() const { return this->m_file.m_szFileName; }
	inline const int getFileSize() const { return this->m_file.m_nFileSize; }

	//주어진 배열에 복사도 하고, 서비스로 그거 리턴도 해줌;
	char* getData(char* p_szDest, int p_iStart, int p_iSize);
	char* getRawData(){ return readAll(); }
		
	char* operator()(char* p_szDest, int p_iStart, int p_iSize){ return getData(p_szDest, p_iStart, p_iSize); }
	char* operator()(){ return getRawData(); }

private:
	char* readAll();
	char* readRange(char* p_szDest, int p_iStart, int p_iSize);

	//스트림 복사 안되니까 이 클래스도 복사하면 안 됨!
	CKDMFileRead(const CKDMFileRead&);
	CKDMFileRead& operator=(const CKDMFileRead&);

	std::ifstream m_inputStream;
	SKDMFile m_file;
};

//쓰기만 가능하다.
class CKDMFileWrite{
public:
	const enum WriteMode{
		WRITE_TRUNCATE = 0,
		WRITE_ATEND = 1
	};
public:
	CKDMFileWrite(){}
	CKDMFileWrite(const char* p_szFileName, WriteMode p_eMode = WRITE_ATEND)
		: m_eCurrentMode(p_eMode) { open(p_szFileName); }
	~CKDMFileWrite(){ close(); }

	void open(const char* p_szFileName);
	void close();

	inline bool isOpen() const { return this->m_outputStream.is_open(); }
	inline WriteMode getCurrentMode() const { return m_eCurrentMode; }
	inline std::ofstream* getStream(){ return &(this->m_outputStream); }
	inline const char* getFileName() const { return this->m_szFileName; }
	
	//현재 모드로 데이터 기록
	void writeData(const char* p_szSrc, int p_nFileSize);
	void writeData(const SKDMFile* p_KDMFile);
	void operator()(const char* p_szDest, int p_nFileSize){ this->writeData(p_szDest, p_nFileSize); }
	void operator()(const SKDMFile* p_KDMFile){ this->writeData(p_KDMFile->m_szRawData, p_KDMFile->m_nFileSize); }
	void modifyData(const char* p_szSrc, int p_iStart, int p_iSize);
	void flush(){ this->m_outputStream.flush(); };

	void changeMode(WriteMode p_eMode);	

private:
	void writeDataTruncate(const char* p_szSrc, int p_nFileSize);
	void writeDataTruncate(const SKDMFile* p_KDMFile);
	void writeDataAtEnd(const char* p_szSrc, int p_nFileSize);
	void writeDataAtEnd(const SKDMFile* p_KDMFile);
	void reopenStream();

	//스트림 복사 안되니까 이 클래스도 복사하면 안 됨!
	CKDMFileWrite(const CKDMFileWrite&);
	CKDMFileWrite& operator=(const CKDMFileWrite&);

	char* m_szFileName = 0;
	std::ofstream m_outputStream;
	WriteMode m_eCurrentMode;
};

#endif KDM_SRC_LIBRARY_FILE_READ_WRITE_H