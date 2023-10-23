#pragma once
#include "CPictureDraft.h"
#include "ICanvas.h"
class CPainter
{
public:
	void DrawPicture(const CPictureDraft& draft, ICanvas* canvas)
	{
		for (size_t i = 0; i < draft.GetShapeCount(); i++)
		{
			draft.GetShape(i)->Draw(canvas);
		}
	}
};

