
#pragma once
#include <string>

#define THROW_EXCEPTION( type, note ) throw type( _CRT_WIDE(__FILE__), __LINE__, note );



class Exception
{

public:
	Exception(const wchar_t* file, unsigned int line, const std::string& note = "");

	std::string GetNote() const;
	
	std::string GetFile() const;
	
	std::string GetLine() const;

	std::string GetLocation() const;

private:
	std::string note;
	const wchar_t* file;
	unsigned int line;
};

struct UnhandledException : public Exception
{
	UnhandledException(const wchar_t* file, unsigned int line, const std::string note = "") :
		Exception(file, line, note)
	{
	}
};

struct OutOfBoundsException : public Exception
{
	OutOfBoundsException(const wchar_t* file, unsigned int line, const std::string& note = "") :
		Exception(file, line, note)
	{
	}
};