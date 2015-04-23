﻿#include <iostream>
#include "file-read-write.h"

void CKDMFileRead::open(const char* p_szFileName){
	close();

	this->m_file.m_szFileName = new char[strlen(p_szFileName) + 1];
	memcpy(this->m_file.m_szFileName, p_szFileName, strlen(p_szFileName) + 1);

	//바이너리로 읽음, std::ifstream::in은 내부 스트림에서 읽기
	this->m_inputStream = std::ifstream(p_szFileName, std::ifstream::binary | std::ifstream::in);
	//맨 끝으로 이동
	this->m_inputStream.seekg(0, std::ifstream::end);
	//위치 = 파일 크기
	this->m_file.m_nFileSize = static_cast<int>(this->m_inputStream.tellg());
	//맨 처음으로 이동
	this->m_inputStream.seekg(0, std::ifstream::beg);
}


void CKDMFileRead::close(){
	if (isOpen())
		this->m_inputStream.close();
	if (this->m_file.m_szFileName != 0)
		delete this->m_file.m_szFileName;
	if (this->m_file.m_szRawData != 0)
		delete this->m_file.m_szRawData;

	this->m_file.m_nFileSize = -1;
}

char* CKDMFileRead::getData(char* p_szDest, int p_iStart, int p_iSize){
	if (this->m_file.m_szRawData != 0)
		memcpy(p_szDest, &(this->m_file.m_szRawData[p_iStart]), sizeof(char)*p_iSize);
	else
		readRange(p_szDest, p_iStart, p_iSize);

	return p_szDest;
}

char* CKDMFileRead::readAll(){
	if (isOpen() != true)
		throw std::logic_error("Error: File Not Opened");
	if (this->m_file.m_szRawData != 0)
		return this->m_file.m_szRawData;

	//파일 내용을 가져오기 위한 영역 확보
	this->m_file.m_szRawData = new char[this->m_file.m_nFileSize];

	//파일에서 읽기
	int iCurIndex = static_cast<int>(this->m_inputStream.tellg());
	this->m_inputStream.seekg(0, std::ifstream::beg);
	this->m_inputStream.read(this->m_file.m_szRawData, sizeof(char)*this->m_file.m_nFileSize);
	this->m_inputStream.seekg(0, iCurIndex);

	return m_file.m_szRawData;
}

char* CKDMFileRead::readRange(char* p_szDest, int p_iStart, int p_iSize){
	if (isOpen() != true)
		throw std::logic_error("Error: File Not Opened");

	int iCurIndex = static_cast<int>(this->m_inputStream.tellg());
	this->m_inputStream.seekg(p_iStart, std::ifstream::beg);
	this->m_inputStream.read(p_szDest, sizeof(char)*p_iSize);
	this->m_inputStream.seekg(0, iCurIndex);

	return p_szDest;
}



void CKDMFileWrite::open(const char* p_szFileName){
	close();

	this->m_szFileName = new char[strlen(p_szFileName) + 1];
	memcpy(this->m_szFileName, p_szFileName, strlen(p_szFileName) + 1);

	reopenStream();
}

void CKDMFileWrite::close(){
	if (isOpen())
		this->m_outputStream.close();
	if (this->m_szFileName != 0)
		delete this->m_szFileName;

	this->m_szFileName = 0;
}

void CKDMFileWrite::writeData(const char* p_szSrc, int p_nFileSize){
	this->m_outputStream.write(p_szSrc, p_nFileSize);
}
void CKDMFileWrite::writeData(const SKDMFile* p_KDMFile){
	writeData(p_KDMFile->m_szRawData, p_KDMFile->m_nFileSize);
}

void CKDMFileWrite::changeMode(WriteMode p_eMode){
	this->m_eCurrentMode = p_eMode;
	reopenStream();
}

void CKDMFileWrite::modifyData(const char* p_szSrc, int p_iStart, int p_iSize){
	int iCurIndex = static_cast<int>(this->m_outputStream.tellp());
	this->m_outputStream.seekp(p_iStart);
	this->m_outputStream.write(p_szSrc, p_iSize);
	this->m_outputStream.seekp(0, iCurIndex);
}

void CKDMFileWrite::writeDataTruncate(const char* p_szSrc, int p_nFileSize){
	WriteMode currentModeBackup = this->m_eCurrentMode;

	if (this->m_eCurrentMode != WRITE_TRUNCATE)
		changeMode(WRITE_TRUNCATE);

	writeData(p_szSrc, p_nFileSize);
	this->m_eCurrentMode = currentModeBackup;
}

void CKDMFileWrite::writeDataTruncate(const SKDMFile* p_KDMFile){
	writeDataTruncate(p_KDMFile->m_szRawData, p_KDMFile->m_nFileSize);
}

void CKDMFileWrite::writeDataAppend(const char* p_szSrc, int p_nFileSize){
	WriteMode currentModeBackup = this->m_eCurrentMode;

	if (this->m_eCurrentMode != WRITE_APPEND)
		changeMode(WRITE_APPEND);

	writeData(p_szSrc, p_nFileSize);
	this->m_eCurrentMode = currentModeBackup;
}

void CKDMFileWrite::writeDataAppend(const SKDMFile* p_KDMFile){
	writeDataAppend(p_KDMFile->m_szRawData, p_KDMFile->m_nFileSize);
}

void CKDMFileWrite::reopenStream(){
	std::ios_base::openmode mode = std::ios_base::binary;

	if (m_eCurrentMode == WRITE_TRUNCATE)
		mode |= std::ios_base::trunc;
	else
		mode |= std::ios_base::app;

	this->m_outputStream = std::ofstream(m_szFileName, mode);
}