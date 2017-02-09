#pragma once

class Vide {};

template <class Chain = Vide>
class Incopiable : Chain 
{
public:

	Incopiable(const Incopiable&) = delete;
	Incopiable& operator=(const Incopiable&) = delete;

protected:

	constexpr Incopiable() = default;
	~Incopiable() = default;
};