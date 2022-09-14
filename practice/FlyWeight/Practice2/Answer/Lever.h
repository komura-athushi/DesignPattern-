#pragma once

enum EnLever {
	enLever_General = 0,
	enLever_Red = 1,
	enLever_Blue = 2,
	enLever_Number = 3
};

class Lever
{
public:
	void Init(EnLever enLever,const int maxInstance);
	void AddPosition(const Vector3& position)
	{
		m_positionList.push_back(position);
	}
	void UpdateInstancingData()
	{
		int instanceNumber = 0;
		for(auto& position : m_positionList)
		{
			m_modelRender.UpdateInstancingData(instanceNumber, position, Quaternion::Identity, Vector3::One);
			instanceNumber++;
		}
	}
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
	std::vector<Vector3> m_positionList;

};

