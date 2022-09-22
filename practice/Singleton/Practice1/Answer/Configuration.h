#pragma once

class Configuration
{
private:
	Configuration(){}
public:
	static Configuration* GetInstance();
	virtual ~Configuration(){}
	virtual std::wstring GetSolutionConfiguration() = 0;
};

class DebugConfiguration : public Configuration
{
public:
	~DebugConfiguration(){}
	std::wstring GetSolutionConfiguration() override { return L"ソリューション構成はDebugです。"; }
};

class ReleaseConfiguration : public Configuration
{
public:
	~ReleaseConfiguration() {}
	std::wstring GetSolutionConfiguration() override { return L"ソリューション構成はReleaseです。"; }
};

