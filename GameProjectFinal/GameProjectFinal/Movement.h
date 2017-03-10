#pragma once



class Movement
{

	double m_CurMovePerRound;
	double m_MaxMovePerRound;

public:

	Movement();

	Movement(double maxMovePerRound);

	void RoundReset();

};