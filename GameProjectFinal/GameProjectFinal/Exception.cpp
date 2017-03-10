
#include "Exception.h"

Exception::Exception(const wchar_t* file, unsigned int line, const std::wstring& note)
	:
	note(note),
	file(file),
	line(line)
{}

const std::wstring& Exception::GetNote() const
{
	return note;
}

const std::wstring& Exception::GetFile() const
{
	return file;
}

unsigned int Exception::GetLine() const
{
	return line;
}

std::wstring Exception::GetLocation() const
{
	return std::wstring(L"Line [") + std::to_wstring(line) + L"] in " + file;
}