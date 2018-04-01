#pragma once

#include <vector>

#include "BaseModelManager.h"
#include "Clock.h"


class AnimatedModelManager : public BaseModelManager
{

	time_point<high_resolution_clock> begin;

	struct AnimationPiece
	{
		duration_T duration;
		Model2D* model;

		AnimationPiece(duration_T duration, Model2D* model) :
			duration{ duration },
			model{ model }
		{
		}
	};

	std::vector<AnimationPiece> m_AnimationTimeline;

	bool defaultIsOn;

public:

	AnimatedModelManager(Model2D* defaultModel) :
		BaseModelManager{ defaultModel },
		begin{ Clock::get().GetNow() },
		defaultIsOn{ true }
	{
	}

	AnimatedModelManager(const AnimatedModelManager& other) :
		BaseModelManager{ other },
		m_AnimationTimeline{ other.m_AnimationTimeline },
		begin{ other.begin },
		defaultIsOn{ other.defaultIsOn }
	{
	}

	virtual Model2D* Render() override
	{
		///////
		if (defaultIsOn)
		{
			m_Model->Render();
			return m_Model;
		}
		else
		{
			if (Clock::get().GetNow() >= begin + m_AnimationTimeline[0].duration)
			{
				m_AnimationTimeline.erase(m_AnimationTimeline.begin());
				begin = Clock::get().GetNow();
			}

			if (m_AnimationTimeline.size() == 0)
			{
				defaultIsOn = true;
				m_Model->Render();
				return m_Model;
			}
			else
			{
				m_AnimationTimeline[0].model->Render();
				return m_AnimationTimeline[0].model;
			}
		}
	}

	virtual void AddAnimation(duration_T duration, Model2D* model) override
	{
		AnimationPiece piece{ duration, model };
		m_AnimationTimeline.push_back(piece);
		defaultIsOn = false;
	}

	virtual void OverrideAnimation(duration_T duration, Model2D* model) override
	{
		m_AnimationTimeline.clear();
		AddAnimation(duration, model);
		defaultIsOn = false;
	}

	virtual void ToDefault() override
	{
		m_AnimationTimeline.clear();
		defaultIsOn = true;
	}

	virtual Clonable* clone() const override
	{
		return new AnimatedModelManager(*this);
	}
};