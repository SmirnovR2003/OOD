#pragma once
#include "IDocument.h"
#include <vector>
#include "IHistoryDocumentCommand.h"
#include "IDocumentHistory.h"

class CDocument :
    public IDocument
{
public:
    CDocument();
    // Вставляет параграф текста в указанную позицию (сдвигая последующие элементы)
    // Если параметр position не указан, вставка происходит в конец документа
    std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
        std::optional<size_t> position = std::nullopt) override;
    // Вставляет изображение в указанную позицию (сдвигая последующие элементы)
    // Параметр path задает путь к вставляемому изображению
    // При вставке изображение должно копироваться в подкаталог images
    // под автоматически сгенерированным именем
    std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height,
        std::optional<size_t> position = std::nullopt) override;
    // Возвращает количество элементов в документе
    size_t GetItemsCount()const override;
    // Доступ к элементам изображения
    CConstDocumentItem GetItem(size_t index)const override;
    CDocumentItem GetItem(size_t index) override;
    void ReplaceText(size_t position, const std::string& text) override;
    void ResizeImage(size_t position, int width, int height) override;
    // Удаляет элемент из документа
    void DeleteItem(size_t index) override;
    // Возвращает заголовок документа
    std::string GetTitle()const override;
    // Изменяет заголовок документа
    void SetTitle(const std::string& title) override;
    // Сообщает о доступности операции Undo
    bool CanUndo()const override;
    // Отменяет команду редактирования
    void Undo() override;
    // Сообщает о доступности операции Redo
    bool CanRedo()const override;
    // Выполняет отмененную команду редактирования
    void Redo() override;
    // Сохраняет документ в формате html. Изображения сохраняются в подкаталог images.
    // Пути к изображениям указываются относительно пути к сохраняемому HTML файлу
    void Save(const std::string& path)const override;
    void InsertParagraphWithoutAddingToHisotry(const std::string& text,
        std::optional<size_t> position = std::nullopt) override;
    void InsertImageWithoutAddingToHisotry(const std::string& path, int width, int height,
        std::optional<size_t> position = std::nullopt) override;
    void DeleteItemWithoutAddingToHisotry(size_t index) override;
    void SetTitleWithoutAddingToHisotry(const std::string& title) override;
    void ResizeImageWithoutAddingToHisotry(size_t position, int width, int height) override;
    void ReplaceTextWithoutAddingToHisotry(size_t position, const std::string& text) override;
private:
    std::string m_title;
    std::vector<std::shared_ptr<CDocumentItem>> m_documentItems;
    std::unique_ptr<IDocumentHistory> m_history;
};

