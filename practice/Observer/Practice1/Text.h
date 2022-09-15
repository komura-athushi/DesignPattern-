#pragma once
class Text : public IGameObject
{
public:
	~Text(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetText(std::wstring text)
	{
		m_fontRender.SetText(text.c_str());
	}
private:
	FontRender m_fontRender;
};

