#include "stdafx.h"
#include "Configuration.h"

Configuration* Configuration::GetInstance()
{
#ifdef _DEBUG
static Configuration* instance = new DebugConfiguration();
#endif
#ifdef _RELEASE
static Configuration* instance = new ReleaseConfiguration();;
#endif
return instance;
}