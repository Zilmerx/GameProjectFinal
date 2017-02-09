
#pragma once
#include <string>

#define THROW_EXCEPTION( note ) throw Exception( _CRT_WIDE(__FILE__), __LINE__, note );

class Exception
{
public:
	Exception(const wchar_t* file, unsigned int line, const std::wstring& note = L"")
		:
		note(note),
		file(file),
		line(line)
	{}
	const std::wstring& GetNote() const
	{
		return note;
	}
	const std::wstring& GetFile() const
	{
		return file;
	}
	unsigned int GetLine() const
	{
		return line;
	}
	std::wstring GetLocation() const
	{
		return std::wstring(L"Line [") + std::to_wstring(line) + L"] in " + file;
	}
private:
	std::wstring note;
	std::wstring file;
	unsigned int line;
};