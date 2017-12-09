
#pragma once
#include <string>

#define THROW_EXCEPTION( type, note ) throw type( _CRT_WIDE(__FILE__), __LINE__, note );



class Exception
{

public:
	Exception(const wchar_t* file, unsigned int line, const std::wstring& note = L"");

	const std::wstring& GetNote() const;

	const std::wstring& GetFile() const;

	unsigned int GetLine() const;

	std::wstring GetLocation() const;

private:
	std::wstring note;
	std::wstring file;
	unsigned int line;
};

struct UnhandledException : public Exception
{
	UnhandledException(const wchar_t* file, unsigned int line, const std::wstring& note = L"") :
		Exception(file, line, note)
	{
	}
};

struct OutOfBoundsException : public Exception
{
	OutOfBoundsException(const wchar_t* file, unsigned int line, const std::wstring& note = L"") :
		Exception(file, line, note)
	{
	}
};