#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
class IDocumentHistory
{
public:

    virtual void AddCommandToHistory(std::shared_ptr<IHistoryDocumentCommand> command) = 0;
    // �������� � ����������� �������� Undo
    virtual bool CanUndo()const = 0;
    // �������� ������� ��������������
    virtual void Undo() = 0;
    // �������� � ����������� �������� Redo
    virtual bool CanRedo()const = 0;
    // ��������� ���������� ������� ��������������
    virtual void Redo() = 0;
};

