
#include "Exception.h"
#include <string>

Exception::Exception(const wchar_t* file, unsigned int line, const std::string& note) :
	note(note),
	file(file),
	line(line)
{
}

std::string Exception::GetNote() const
{
	return note;
}

std::string Exception::GetFile() const
{
	std::wstring File(file);
	return std::string(File.begin(), File.end());
}

std::string Exception::GetLine() const
{
	return std::to_string(line);
}

std::string Exception::GetLocation() const
{
	std::wstring File(file);

	return std::string("Line [") + std::to_string(line) + "] in " + GetFile();
}