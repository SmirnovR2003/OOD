#pragma once
#include "IDocumentHistory.h"
#include <vector>
#include <memory>
#include "IHistoryDocumentCommand.h"
#include "CDocument.h"
class CDocumentHistory :
    public IDocumentHistory
{
public:

    void AddCommandToHistory(std::shared_ptr<IHistoryDocumentCommand> command) override
    {
        if (m_historyIndex < M_MAX_HISTORY_INDEX)
        {
            for (size_t i = m_historyIndex; i < m_history.size(); i++)
            {
                m_history[i]->Destroy();
                m_history.erase(m_history.begin() + m_historyIndex);
            }
        }
        else
        {
            m_history.erase(m_history.begin());
        }
        m_history.push_back(command);
        m_historyIndex++;
    }
    // Сообщает о доступности операции Undo
    bool CanUndo()const override
    {
        return m_historyIndex > 0;
    }

    // Отменяет команду редактирования
    void Undo() override
    {
        if (!CanUndo())
        {
            throw std::logic_error("can't undo");
        }

        m_history[--m_historyIndex]->Unexecute();
    }

    // Сообщает о доступности операции Redo
    bool CanRedo()const override
    {
        return m_historyIndex < m_history.size();
    }

    // Выполняет отмененную команду редактирования
    void Redo() override
    {
        if (!CanRedo())
        {
            throw std::logic_error("can't redo");
        }
        m_history[m_historyIndex++]->Execute();
    }

private:
    std::vector<std::shared_ptr<IHistoryDocumentCommand>> m_history;
    size_t m_historyIndex = 0;
    const size_t M_MAX_HISTORY_INDEX = 9;
};

