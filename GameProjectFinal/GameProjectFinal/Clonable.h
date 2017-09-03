#pragma once


struct Clonable
{
	virtual Clonable *clone() const = 0;
	virtual ~Clonable() = default;
protected:
	Clonable() = default;
	Clonable(const Clonable &) = default;
};