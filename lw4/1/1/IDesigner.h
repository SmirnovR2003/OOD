#pragma once

#include <iostream>
#include "CPictureDraft.h"

class IDesigner
{
	virtual CPictureDraft CreateDraft(std::istream& strm) = 0;
};

