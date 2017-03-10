#pragma once


template<class T>
class LimitedT
{
private:
	T m_min;
	T m_max;

	T m_value;

public:

	LimitedT() :
		m_value{},
		m_min{},
		m_max{}
	{
	}

	LimitedT(T min, T max) :
		m_value {},
		m_min{ min },
		m_max{ max }
	{
	}

	LimitedT(T value, T min, T max) :
		m_value { value },
		m_min{ min },
		m_max{ max }
	{

	}

	void SetValue(T value)
	{
		if (value < min)
		{
			m_value = min;
		}
		else if (value > max)
		{
			m_value = max;
		}
		else
		{
			m_value = value;
		}
	}

	T GetValue() const
	{
		return m_value;
	}

	void SetToMin()
	{
		m_value = min;
	}

	void SetToMax()
	{
		m_value = max;
	}

	void SetMin(T min)
	{
		m_min = min;
	}

	void SetMax(T max)
	{
		m_max = max;
	}

	T GetMin() const
	{
		return m_min;
	}

	T GetMax() const
	{
		return m_max;
	}

	double GetPercentage() const
	{
		return (double)(GetValue() - GetMin()) / (double)(GetMax() - GetMin());
	}
};