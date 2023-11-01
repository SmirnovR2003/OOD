#pragma once
#include <memory>
#include "IHistoryDocumentCommand.h"
class IDocumentHistory
{
public:

    virtual void AddCommandToHistory(std::shared_ptr<IHistoryDocumentCommand> command) = 0;
    // Сообщает о доступности операции Undo
    virtual bool CanUndo()const = 0;
    // Отменяет команду редактирования
    virtual void Undo() = 0;
    // Сообщает о доступности операции Redo
    virtual bool CanRedo()const = 0;
    // Выполняет отмененную команду редактирования
    virtual void Redo() = 0;
};

