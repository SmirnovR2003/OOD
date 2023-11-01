#pragma once
class IHistoryDocumentCommand
{
public:

	virtual void Execute() = 0;

	virtual void Unexecute() = 0;

	virtual void Destroy() = 0;

	virtual ~IHistoryDocumentCommand() = default;
};

