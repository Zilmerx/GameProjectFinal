
#include "Movement.h"

Movement::Movement() :
	m_CurMovePerRound{ 0.0 },
	m_MaxMovePerRound{ 0.0 }
{
}

Movement::Movement(double maxMovePerRound) :
	m_CurMovePerRound{ maxMovePerRound },
	m_MaxMovePerRound{ maxMovePerRound }
{
}

void Movement::RoundReset()
{
	m_CurMovePerRound = m_MaxMovePerRound;
}