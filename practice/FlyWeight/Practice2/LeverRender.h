#pragma once
class LeverRender : public IGameObject
{
public:
	LeverRender();
	~LeverRender();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	static const int HEIGHTNUMBER = 10;
	static const int WIDTHNUMBER = 10;
private:
	ModelRender	m_modelRender[HEIGHTNUMBER*WIDTHNUMBER];
	Vector3 m_position;
	Quaternion m_rotation;
	Vector3 m_scale = Vector3::One;
};

