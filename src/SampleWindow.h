#pragma once
#include "BaseWindow.h"

class SampleWindow: public BaseWindow<SampleWindow>
{
protected:
	virtual PWSTR ClassName() const override;

public:
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};
