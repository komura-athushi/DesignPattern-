#pragma once

//ƒŒƒo[‚Ìí—ŞB
enum EnLever {
	enLever_General = 0,
	enLever_Red = 1,
	enLever_Blue = 2,
};

class Lever
{
public:
	void Init(EnLever enLever,const Vector3& position);
	void Draw(RenderContext& rc)
	{
		m_modelRender.Draw(rc);
	}
	const EnLever GetEnLever() const
	{
		return m_leverState;
	}
private:
	ModelRender m_modelRender;
	EnLever m_leverState = enLever_General;
};

