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
    // ��������� �������� ������ � ��������� ������� (������� ����������� ��������)
    // ���� �������� position �� ������, ������� ���������� � ����� ���������
    std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
        std::optional<size_t> position = std::nullopt) override;
    // ��������� ����������� � ��������� ������� (������� ����������� ��������)
    // �������� path ������ ���� � ������������ �����������
    // ��� ������� ����������� ������ ������������ � ���������� images
    // ��� ������������� ��������������� ������
    std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height,
        std::optional<size_t> position = std::nullopt) override;
    // ���������� ���������� ��������� � ���������
    size_t GetItemsCount()const override;
    // ������ � ��������� �����������
    CConstDocumentItem GetItem(size_t index)const override;
    CDocumentItem GetItem(size_t index) override;
    void ReplaceText(size_t position, const std::string& text) override;
    void ResizeImage(size_t position, int width, int height) override;
    // ������� ������� �� ���������
    void DeleteItem(size_t index) override;
    // ���������� ��������� ���������
    std::string GetTitle()const override;
    // �������� ��������� ���������
    void SetTitle(const std::string& title) override;
    // �������� � ����������� �������� Undo
    bool CanUndo()const override;
    // �������� ������� ��������������
    void Undo() override;
    // �������� � ����������� �������� Redo
    bool CanRedo()const override;
    // ��������� ���������� ������� ��������������
    void Redo() override;
    // ��������� �������� � ������� html. ����������� ����������� � ���������� images.
    // ���� � ������������ ����������� ������������ ���� � ������������ HTML �����
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

